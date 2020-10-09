#ifndef STACK
#define STACK

template <typename T>
class Stack
{
private:
    static const INITIAL_SIZE = 2;

public:
    Stack(int size = INITIAL_SIZE);
    Stack(const Stack &);
    Stack &operator=(const Stack &);
    /*
        push resizes the array if full
    */
    void push(const T &);
    /*
        pop returns the element and removes it from the array,
        if empty print an appropriate message and exit the program
    */
    T pop();
    /*
        utility function, returns the top element
    */
    T peek();
    /*
        utility function, checks if the stack is empty
    */
    bool isEmpty();
    ~Stack();
};

#endif