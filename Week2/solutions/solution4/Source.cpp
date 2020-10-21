#include<iostream>
#include <stack>

double convertToNumber(char c)
{
	return static_cast<int>(c) - static_cast<int>('0');
}

bool isNumber(char c)
{
	return c >= '0' && c <= '9';
}

double doOperation(double a, double b, char operation){
	switch(operation)
	{
		case '+': return a + b;
		case '-': return a - b;
		case '/': return a / b;
		case '*': return a * b;
	}
}

double calculate(std::string term)
{
	std::stack<double> numbers;
	for (char symbol : term)
	{
		if(symbol != ' ')
		{
			if(isNumber(symbol))
			{
				numbers.push(convertToNumber(symbol));
			}
			else if(numbers.size() >= 2)
			{
				double first = numbers.top();
				numbers.pop();
				double second = numbers.top();
				numbers.pop();
				numbers.push(doOperation(second, first, symbol));
			}
		}
	}
	return numbers.top();
}

int main()
{
	std::string term = "4 2 3 * +";
	std::cout << "result: " << calculate(term) << '\n';
	//5 + (6 / 2) * 5 - 7
	std::string term2 = "5 6 2 / 5 * + 7 -";
	std::cout << "result: " << calculate(term2) << '\n';
	return 0;
}