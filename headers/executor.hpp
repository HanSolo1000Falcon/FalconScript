#ifndef fs_executor
#define fs_executor

#include <map>
#include <vector>

#include "token.hpp"

Token evaluateExpression(const std::vector<Token> &expressionTokens, const std::map<int, std::map<std::string, std::any>> &variablesInScope);
void executeFunction(const std::vector<Token> &functionInstructions, const std::map<std::string, std::vector<Token>> &functions);
void execute(const std::vector<Token> &tokens);

#endif