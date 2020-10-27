#include <iostream>
#include <queue>

template<typename T>
std::queue<T> merge(std::queue<T> first, std::queue<T> second)
{
	std::queue<T> result;
	while(!first.empty() && !second.empty())
	{
		if(first.front() < second.front())
		{
			result.push(first.front());
			first.pop();
		}
		else
		{
			result.push(second.front());
			second.pop();
		}
	}
	while(!first.empty())
	{
		result.push(first.front());
		first.pop();
	}
	while (!second.empty())
	{
		result.push(second.front());
		second.pop();
	}
	return result;
}

template<typename T>
void printQueue(std::queue<T> q)
{
	while(!q.empty())
	{
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << '\n';
}

int main()
{
	std::queue<double> a;
	a.push(1);
	a.push(1.34);
	a.push(4.20);
	a.push(6.99);
	a.push(17.11);
	a.push(21);
	a.push(33.33);
	a.push(42.24);
	a.push(120.89);
	a.push(133.4895);
	a.push(150.4488);

	std::queue<double> b;
	b.push(0);
	b.push(8.5);
	b.push(17.11);
	b.push(22.04);
	b.push(30.03);
	b.push(44);
	b.push(54.00001);
	b.push(77.5);
	b.push(88.77);

	std::queue<double> c = merge(a, b);
	printQueue(c);
	return 0;
}