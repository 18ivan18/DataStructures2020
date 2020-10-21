#include <stack>
#include <iostream>

template <typename T>
class StackWithMax
{
    std::stack<T> mainStack;
    std::stack<T> trackStack;

public:
    void push(T x)
    {
        mainStack.push(x);
        if (mainStack.size() == 1)
        {
            trackStack.push(x);
            return;
        }

        // If current element is greater than
        // the top element of track stack, push
        // the current element to track stack
        // otherwise push the element at top of
        // track stack again into it.
        if (x > trackStack.top())
            trackStack.push(x);
        else
            trackStack.push(trackStack.top());
    }

    T getMax()
    {
        return trackStack.top();
    }

    T pop()
    {
        trackStack.pop();
        return mainStack.pop();
    }
};

int main()
{
    StackWithMax<int> stackWithMax;
    int input[] = {4, 19, 7, 14, 20};
    std::cout << "Max Values in stack are ";
    for (int i : input)
    {
        stackWithMax.push(i);
        std::cout << stackWithMax.getMax() << " ";
    }
    std::cout << std::endl;

    return 0;
}