#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int main_cppy_w4_t11_1()
{
    queue<string> ops;
    string num;
    int count;

    cin >> num;
    cin >> count;

    for (int i = 0; i < count; ++i)
    {
        string operation;
        cin >> operation;
        string operand;
        cin >> operand;
        ops.push(operation);
        ops.push(operand);
    }

    for (size_t i = 0; i < ops.size() / 2; ++i)
    {
        cout << '(';
    }
    cout << num;

    while (!ops.empty())
    {
        string operation = ops.front();
        ops.pop();
        cout << ") " << operation;
        string operand = ops.front();
        ops.pop();
        cout << " " << operand;
    }
    
    cout << endl;

    return 0;
}

int main_cppy_w4_t11_2()
{
    vector<string> ops;
    string num;
    int count;
    map<string, int> priorities = { {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2} };

    cin >> num;
    cin >> count;

    for (int i = 0; i < count; ++i)
    {
        string operation;
        cin >> operation;
        string operand;
        cin >> operand;
        ops.push_back(operation);
        ops.push_back(operand);
    }

    int prev_op_priority = 2;
    for (size_t i = 0; i < ops.size(); i += 2)
    {
        if (priorities[ops[i]] > prev_op_priority)
        {
            cout << '(';
        }
        prev_op_priority = priorities[ops[i]];
    }

    cout << num;

    prev_op_priority = 2;
    for (size_t i = 0; i < ops.size(); i += 2)
    {
        if (priorities[ops[i]] > prev_op_priority)
        {
            cout << ')';
        }
        cout << " " << ops[i];
        cout << " " << ops[i + 1];
        prev_op_priority = priorities[ops[i]];
    }

    cout << endl;

    return 0;
}

// Teacher's solution

namespace t1
{

    // ќпределим структуру дл€ удобной организации данных
    struct Operation {
        // ѕараметры по умолчанию нужны дл€ конструировани€ вектора
        // ненулевого размера (*)
        char type = 0;
        int number = 0;
    };

    int main1() {
        int initial_number;
        cin >> initial_number;

        int number_of_operations;
        cin >> number_of_operations;
        vector<Operation> operations(number_of_operations);  // (*)
        for (int i = 0; i < number_of_operations; ++i) {
            cin >> operations[i].type;
            cin >> operations[i].number;
        }

        deque<string> expression;
        expression.push_back(to_string(initial_number));
        for (const auto& operation : operations) {
            expression.push_front("(");
            expression.push_back(") ");
            expression.push_back(string(1, operation.type));
            expression.push_back(" ");
            expression.push_back(to_string(operation.number));
        }

        for (const string& s : expression) {
            cout << s;
        }

        return 0;
    }

}

namespace t2
{
    // ќпределим структуру дл€ удобной организации данных
    struct Operation {
        // ѕараметры по умолчанию нужны дл€ конструировани€ вектора
        // ненулевого размера, см. (*)
        char type = 0;
        int number = 0;
    };


    // ‘ункци€ дл€ проверки выполнени€ требований постановки скобок
    bool NeedBrackets(char last, char current) {
        return (last == '+' || last == '-') && (current == '*' || current == '/');
    }


    int main2() {
        int initial_number;
        cin >> initial_number;

        int number_of_operations;
        cin >> number_of_operations;
        vector<Operation> operations(number_of_operations);  // (*)
        for (int i = 0; i < number_of_operations; ++i) {
            cin >> operations[i].type;
            cin >> operations[i].number;
        }

        deque<string> expression;
        expression.push_back(to_string(initial_number));
        // первое число никогда не обрамл€етс€ скобками
        char last_type = '*';
        for (const auto& operation : operations) {
            // ≈сли услови€ удовлетворены, обрамл€ем последовательность скобками
            if (NeedBrackets(last_type, operation.type)) {
                expression.push_front("(");
                expression.push_back(")");
            }
            expression.push_back(" ");
            expression.push_back(string(1, operation.type));
            expression.push_back(" ");
            expression.push_back(to_string(operation.number));

            last_type = operation.type;
        }

        for (const string& s : expression) {
            cout << s;
        }

        return 0;
    }
}