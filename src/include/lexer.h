#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum TokenType{
    TK_INT,
    TK_ADD,
    TK_SUB,
    TK_DIV,
    TK_MULT,
    TK_POT,
    TK_LPAREN,
    TK_RPAREN,
    TK_SEMI,
    TK_EOF,
};

struct Token{
    TokenType type;
    std::string value;
};

class Lexer{
public:
    Lexer(const std::string& source);
    std::vector<Token> getTokens();
private:
    std::string source;
    size_t pos;
};


#endif // !LEXER
