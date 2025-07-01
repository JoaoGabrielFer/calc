#include "include/lexer.h"
#include <cctype>
#include <stdexcept>
#include <vector>

Lexer::Lexer(const std::string& source) : source(source), pos(0) {
};

std::vector<Token> Lexer::getTokens() {
    std::vector<Token> tokens;
    while (pos < source.length()) {
        
        char currentChar = source[pos];

        if (std::isspace(currentChar)) {
            pos++;
            continue; 
        }
        
        else if (std::isdigit(currentChar)) {
            std::string number_str;
            while (pos < source.length() && std::isdigit(source[pos])) {
                number_str += source[pos];
                pos++;
            }
            tokens.push_back({TK_INT, number_str});
            continue;
        }

        else {
            switch (currentChar) {
                case '+':
                    tokens.push_back({TK_ADD, "+"});
                    break;
                case '-':
                    tokens.push_back({TK_SUB, "-"});
                    break;
                case '*':
                    tokens.push_back({TK_MULT, "*"});
                    break;
                case '/':
                    tokens.push_back({TK_DIV, "/"});
                    break;
                case '^':
                    tokens.push_back({TK_POT, "^"});
                    break;
                case '(':
                    tokens.push_back({TK_LPAREN, "("});
                    break;
                case ')':
                    tokens.push_back({TK_RPAREN, ")"});
                    break;
                case ';':
                    tokens.push_back({TK_SEMI, ";"});
                    break;
                default:
                    throw std::runtime_error("Caractere inválido na expressão: " + std::string(1, currentChar));
            }
            pos++;
        }
    }

    tokens.push_back({TK_EOF, ""});
    return tokens;
}
