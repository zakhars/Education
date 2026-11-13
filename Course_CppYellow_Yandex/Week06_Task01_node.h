#pragma once

#include <string>
#include <memory>

#include "Week06_Task01_date.h"
#include "Week06_Task01_token.h"

struct Node
{
    virtual bool Evaluate(const Date& d, const std::string& e) = 0;
};

struct EmptyNode : public Node
{
    EmptyNode() = default;
    bool Evaluate(const Date& d, const std::string& e) override;
};


struct LogicalOperationNode : public Node
{
    LogicalOperation operation;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    LogicalOperationNode(LogicalOperation op, std::shared_ptr<Node> left, std::shared_ptr<Node> right) :
        operation(op), left(left), right(right) {}
    bool Evaluate(const Date& d, const std::string& e) override;
};

struct DateComparisonNode : public Node
{
    Comparison cmp;
    Date date;

    DateComparisonNode(Comparison cmp, const Date& date) : cmp(cmp), date(date) {}
    bool Evaluate(const Date& d, const std::string& e) override;
};

struct EventComparisonNode : public Node
{
    Comparison cmp;
    std::string event;

    EventComparisonNode(Comparison cmp, const std::string& event) : cmp(cmp), event(event) {}
    bool Evaluate(const Date& d, const std::string& e) override;
};
