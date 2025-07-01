#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <utility>
#include "lexer.h"

class Expr{
public:
    virtual ~Expr() = default;
    class Binary;
    class Unary;
    class Number;
    class Grouping;
};

class Expr::Binary : public Expr{
public:
    Binary(std::unique_ptr<Expr> left, Token operator_token, std::unique_ptr<Expr> right)
        : left(std::move(left)),
          op(operator_token),
          right(std::move(right)) {}

    const std::unique_ptr<Expr> left;
    const Token op;
    const std::unique_ptr<Expr> right;
};

class Expr::Unary : public Expr{
public:
    Unary(Token operator_token, std::unique_ptr<Expr> right)
        : op(operator_token),
          right(std::move(right))
    {}

    const Token op;
    const std::unique_ptr<Expr> right;
};

class Expr::Number : public Expr{
public:
    //only accepts ints for now
    explicit Number(int value) : value(value) {};

    const int value;
};

class Expr::Grouping : public Expr{
public:
    explicit Grouping(std::unique_ptr<Expr> expression)
        : expression(std::move(expression))
    {}

    const std::unique_ptr<Expr> expression;
};


#endif // !PARSER_H
