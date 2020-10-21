#include <iostream>
#include <stack>
#include <string>
#include <fstream>

std::string isBalanced(std::string s)
{
    std::stack<char> st;

    for (auto c : s)
    {
        switch (c)
        {
        case '{':
        case '(':
        case '[':
            st.push(c);
            break;
        case '}':
            if (st.empty() || (st.top() != '{'))
            {
                return "NO";
            }
            st.pop();
            break;
        case ')':
            if (st.empty() || (st.top() != '('))
            {
                return "NO";
            }
            st.pop();
            break;
        case ']':
            if (st.empty() || (st.top() != '['))
            {
                return "NO";
            }
            st.pop();
            break;
        }
    }
    return st.empty() ? "YES" : "NO";
}

int main()
{
    int t;
    std::string filename;
    std::cin >> filename;
    std::ifstream file;
    file.open(filename);
    file >> t;

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        std::string s;
        file >> s;
        std::cout << s << '\n';
        std::string result = isBalanced(s);

        std::cout << result << "\n";
    }

    return 0;
}
