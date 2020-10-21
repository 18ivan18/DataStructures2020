#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main()
{
    std::stack<std::string> operators;
    std::stack<double> values; // operands

    // An example of an arithmetic expression.
    std::string expr = "( ( 1 + sqrt ( 5.0 ) ) / 2.0 )";

    std::vector<std::string> tokens = split(expr, ' ');

    for (std::string token : tokens)
    {
        if (!token.compare("("))
        {
            continue;
        }
        if (!token.compare("+") || !token.compare("-") || !token.compare("*") || !token.compare("/") || !token.compare("sqrt"))
        {
            operators.push(token);
        }
        else if (!token.compare(")"))
        {
            std::string op = operators.top();
            operators.pop();

            // Pop the first operand.
            double val = values.top();
            values.pop();
            if (!op.compare("+"))
            {
                val = values.top() + val;
                values.pop();
            }
            if (!op.compare("-"))
            {
                val = values.top() - val;
                values.pop();
            }
            if (!op.compare("*"))
            {
                val = values.top() * val;
                values.pop();
            }
            if (!op.compare("/"))
            {
                val = values.top() / val;
                values.pop();
            }
            if (!op.compare("sqrt"))
            {
                val = sqrt(val);
            }
            values.push(val);
        }
        else
        {
            values.push(std::stod(token));
        }
    }

    // At the end, there should be one value on the stack - the value of the expression.
    double result = values.top();
    std::cout << "Result: " << result << "\n";
}