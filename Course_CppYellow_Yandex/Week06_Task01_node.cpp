#include <string>
#include <stdexcept>

#include "Week06_Task01_node.h"
#include "Week06_Task01_token.h"

using namespace std;

bool EmptyNode::Evaluate(const Date& d, const string& e)
{
    return true; // Always true (empty condition)
}

bool LogicalOperationNode::Evaluate(const Date& d, const string& e)
{
    if (operation == LogicalOperation::And)
    {
        return left->Evaluate(d, e) && right->Evaluate(d, e);
    }
    if (operation == LogicalOperation::Or)
    {
        return left->Evaluate(d, e) || right->Evaluate(d, e);
    }
    throw logic_error("Unexpected logical operation");
};

bool DateComparisonNode::Evaluate(const Date& d, const string& e)
{
    return Compare(d, date, cmp);
};

bool EventComparisonNode::Evaluate(const Date& d, const string& e)
{
    return Compare(e, event, cmp);
};
