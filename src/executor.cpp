#include <vector>
#include <map>
#include <string>
#include <any>

#include "../headers/token.hpp"

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
}
