#ifndef fs_tokentype
#define fs_tokentype

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
    TRUE,
    LOC,
    WHILE,

    STANDARD,

    EOF_
};

#endif
