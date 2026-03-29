//
// Created by falcon1k on 3/28/26.
//

#ifndef FALCON_SCRIPT_TOKEN_HPP
#define FALCON_SCRIPT_TOKEN_HPP
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

#endif //FALCON_SCRIPT_TOKEN_HPP