#include <vector>
#include <map>
#include <string>
#include <iostream>

#include "../headers/token.hpp"

void executeFunction(const std::vector<Token> &functionInstructions, const std::map<std::string, std::vector<Token>> &functions) {
    int currentScope = 0;
    std::map<int, std::map<std::string, std::any>> variablesInScope;

    for (auto i = 0; i < functionInstructions.size(); ++i) {
        const auto &instruction = functionInstructions[i];

        switch (instruction.type) {
            case LEFT_BRACE:
                variablesInScope.emplace(currentScope, std::map<std::string, std::any>());
                ++currentScope;
                break;

            case RIGHT_BRACE:
                variablesInScope.erase(currentScope);
                --currentScope;
                break;

            case LOC: {
                auto& currentScopeVariables = variablesInScope[currentScope];
                const auto& identifier = functionInstructions[i + 1];
                const auto& value = functionInstructions[i + 3];
                currentScopeVariables[identifier.lexeme] = value.value;
                i += 4;
                break;
            }

            case STANDARD: {
                const auto& functionName = functionInstructions[i + 2].lexeme;

                if (functionName == "Print") {
                    const auto& value = functionInstructions[i + 3];
                    std::cout << std::any_cast<std::string>(functionInstructions[i + 4].value) << '\n';
                }

                while (functionInstructions[i].type != RIGHT_PAREN) {
                    ++i;
                }
                break;
            }
        }
    }
}

void execute(const std::vector<Token> &tokens) {
    std::map<std::string, std::vector<Token>> functions;

    std::string currentFunctionName;
    std::vector<Token> currentFunction;

    for (const auto &token : tokens) {
        if (token.type == FNC) {
            if (!currentFunction.empty()) {
                functions.emplace(currentFunctionName, currentFunction);
            }

            currentFunction.clear();
        }

        if (currentFunction.size() == 1) {
            currentFunctionName = token.lexeme;
        }

        currentFunction.emplace_back(token);
    }

    functions.emplace(currentFunctionName, currentFunction);

    executeFunction(functions["Main"], functions);
}