//
// Created by falcon1k on 3/28/26.
//

#ifndef FALCON_SCRIPT_TOKEN_FACTORY_HPP
#define FALCON_SCRIPT_TOKEN_FACTORY_HPP

enum TokenType {
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,

    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,

    IDENTIFIER,
    STRING,
    NUMBER,

    AND,
    ELSE,
    FALSE,
    FNC,
    FOR,
    IF,
    NIL,
    OR,
    RETURN,
    THIS,
    TRUE,
    VAR,
    WHILE,

    STANDARD,
    FUNCTION_CALL,

    EOF_
};

#endif //FALCON_SCRIPT_TOKEN_FACTORY_HPP
