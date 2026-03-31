#ifndef fs_token
#define fs_token

#include <any>
#include <string>
#include <utility>

#include "token-type.hpp"

class Token {
public:
    const TokenType type;
    const std::string lexeme;
    const std::any value;

    explicit Token(const TokenType &type, std::string lexeme, std::any value) : type(type), lexeme(std::move(lexeme)), value(std::move(value)) {}
};

#endif