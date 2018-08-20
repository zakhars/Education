#pragma once

#include <vector>
#include <stdexcept>

enum class TokenType 
{
  DATE,
  EVENT,
  COLUMN,
  LOGICAL_OP,
  COMPARE_OP,
  PAREN_LEFT,
  PAREN_RIGHT,
};

struct Token 
{
  const std::string value;
  const TokenType type;
};

enum class LogicalOperation
{
    And,
    Or
};

enum class Comparison
{
    LessOrEqual,
    Less,
    Equal,
    GreaterOrEqual,
    Greater,
    NotEqual
};

std::vector<Token> Tokenize(std::istream& cl);

template <typename Val>
bool Compare(const Val& v1, const Val& v2, Comparison cmp)
{
    switch (cmp)
    {
    case Comparison::Less:
        return v1 < v2;
    case Comparison::LessOrEqual:
        return v1 <= v2;
    case Comparison::Equal:
        return v1 == v2;
    case Comparison::Greater:
        return v1 > v2;
    case Comparison::GreaterOrEqual:
        return v1 >= v2;
    case Comparison::NotEqual:
        return v1 != v2;
    }
    throw std::logic_error("Unexpected comparison");
}
