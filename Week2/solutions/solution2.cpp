#include "../stack/linkedListRepresentation/Stack.cpp"
#include <iostream>
#include <string>
#include <sstream>

void twoStackAlgorithm(std::string input)
{
    Stack<char> ops;
    Stack<double> vals;
    std::stringstream ss(input);
    std::string val;

    while (ss.good())
    {
        ss >> val;
        if (val.compare("(") == 0)
            continue;
        else if (val.compare("+") == 0)
            ops.push(val[0]);
        else if (val.compare("*") == 0)
            ops.push(val[0]);
        else if (val.compare(")") == 0)
        {
            char op = ops.pop();
            if (op == '+')
                vals.push(vals.pop() + vals.pop());
            else if (op == '*')
                vals.push(vals.pop() * vals.pop());
        }
        else
            vals.push(std::stod(val));
    }
    std::cout << vals.pop() << std::endl;
}

int main()
{
    std::string input;
    getline(std::cin, input);

    twoStackAlgorithm(input);
}