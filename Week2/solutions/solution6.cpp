#include <iostream>
#include <string>
#include <stack>

int main()
{
    int N;
    std::cin >> N;
    std::stack<std::string> stk;
    std::string st;
    while (N--)
    {
        int n;
        std::cin >> n;
        if (n == 1)
        {
            std::string str;
            std::cin >> str;
            stk.push(st);
            st += str;
        }
        else if (n == 2)
        {
            int k;
            std::cin >> k;
            stk.push(st);
            st.erase(st.size() - k);
        }
        else if (n == 3)
        {
            int k;
            std::cin >> k;
            std::cout << st[k - 1] << std::endl;
        }
        else
        {
            st = stk.top();
            stk.pop();
        }
    }
}