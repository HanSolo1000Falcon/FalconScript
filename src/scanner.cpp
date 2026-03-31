#include <string>
#include <vector>

#include "../headers/token.hpp"

std::vector<Token> tokenize(const std::string &str) {
    std::vector<Token> tokens;

    int current = 0;

    while (current < str.length()) {
        switch (char c = str[current]) {
            case '{':
                tokens.emplace_back(LEFT_BRACE, "{", nullptr);
                ++current;
                break;

            case '}':
                tokens.emplace_back(RIGHT_BRACE, "}", nullptr);
                ++current;
                break;

            case '(':
                tokens.emplace_back(LEFT_PAREN, "(", nullptr);
                ++current;
                break;

            case ')':
                tokens.emplace_back(RIGHT_PAREN, ")", nullptr);
                ++current;
                break;

            case ';':
                tokens.emplace_back(SEMICOLON, ";", nullptr);
                ++current;
                break;

            case '=':
                if (str[current + 1] == '=') {
                    tokens.emplace_back(EQUAL_EQUAL, "==", nullptr);
                    current += 2;
                } else {
                    tokens.emplace_back(EQUAL, "=", nullptr);
                    ++current;
                }
                break;

            case '!':
                if (str[current + 1] == '=') {
                    tokens.emplace_back(BANG_EQUAL, "!=", nullptr);
                    current += 2;
                } else {
                    tokens.emplace_back(BANG, "!", nullptr);
                    ++current;
                }
                break;

            case '>':
                if (str[current + 1] == '=') {
                    tokens.emplace_back(GREATER_EQUAL, ">=", nullptr);
                    current += 2;
                } else {
                    tokens.emplace_back(GREATER, ">", nullptr);
                    ++current;
                }
                break;

            case '<':
                if (str[current + 1] == '=') {
                    tokens.emplace_back(LESS_EQUAL, "<=", nullptr);
                    current += 2;
                } else {
                    tokens.emplace_back(LESS, "<", nullptr);
                    ++current;
                }
            break;

            case '+':
                tokens.emplace_back(PLUS, "+", nullptr);
                ++current;
                break;

            case '-':
                tokens.emplace_back(MINUS, "-", nullptr);
                ++current;
                break;

            case '*':
                tokens.emplace_back(STAR, "*", nullptr);
                ++current;
                break;

            case '/':
                if (str[current + 1] != '/') {
                    tokens.emplace_back(SLASH, "/", nullptr);
                    ++current;
                    break;
                }

                while (str[current] != '\n') {
                    ++current;
                }

                break;

            case ',':
                tokens.emplace_back(COMMA, ",", nullptr);
                ++current;
                break;

            case '.':
                tokens.emplace_back(DOT, ".", nullptr);
                ++current;
                break;

            case '"': {
                auto tempCurrent = current + 1;
                while (str[tempCurrent] != '"') {
                    ++tempCurrent;
                }
                tokens.emplace_back(STRING, str.substr(current + 1, tempCurrent - current - 1), str.substr(current + 1, tempCurrent - current - 1));
                current = tempCurrent + 1;
                break;
            }

            case '&':
                if (str[current + 1] == '&') {
                    tokens.emplace_back(AND, "&&", nullptr);
                    current += 2;
                }
                break;

            case '|':
                if (str[current + 1] == '|') {
                    tokens.emplace_back(OR, "||", nullptr);
                    current += 2;
                }
                break;

            default:
                if (std::isdigit(c)) {
                    auto tempCurrent = current;
                    while (std::isdigit(str[tempCurrent])) {
                        ++tempCurrent;
                    }

                    if (str[tempCurrent] == '.' && std::isdigit(str[tempCurrent + 1])) {
                        ++tempCurrent;

                        while (std::isdigit(str[tempCurrent])) {
                            ++tempCurrent;
                        }
                    }

                    tokens.emplace_back(NUMBER, str.substr(current, tempCurrent - current), std::stod(str.substr(current, tempCurrent - current)));
                    current = tempCurrent;
                } else if (std::isalpha(str[current])) {
                    auto tempCurrent = current;
                    while (std::isalnum(str[tempCurrent])) {
                        ++tempCurrent;
                    }

                    if (const auto identifier = str.substr(current, tempCurrent - current); identifier == "nil") {
                        tokens.emplace_back(NIL, "nil", nullptr);
                    } else if (identifier == "loc") {
                        tokens.emplace_back(LOC, "loc", nullptr);
                    } else if (identifier == "fnc") {
                        tokens.emplace_back(FNC, "fnc", nullptr);
                    } else if (identifier == "if") {
                        tokens.emplace_back(IF, "if", nullptr);
                    } else if (identifier == "else") {
                        tokens.emplace_back(ELSE, "else", nullptr);
                    } else if (identifier == "for") {
                        tokens.emplace_back(FOR, "for", nullptr);
                    } else if (identifier == "while") {
                        tokens.emplace_back(WHILE, "while", nullptr);
                    } else if (identifier == "return") {
                        tokens.emplace_back(RETURN, "return", nullptr);
                    } else if (identifier == "true") {
                        tokens.emplace_back(TRUE, "true", nullptr);
                    } else if (identifier == "false") {
                        tokens.emplace_back(FALSE, "false", nullptr);
                    } else if (identifier == "Standard") {
                        tokens.emplace_back(STANDARD, "Standard", nullptr);
                    } else {
                        tokens.emplace_back(IDENTIFIER, identifier, nullptr);
                    }
                    current = tempCurrent;
                } else {
                    ++current;
                }
            }
        }

    tokens.emplace_back(EOF_, "", nullptr);
    return tokens;
}