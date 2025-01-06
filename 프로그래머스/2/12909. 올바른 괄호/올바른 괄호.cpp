#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stack;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (stack.size() > 0)
        {
            char top = stack.top();
            if (top == '(' && ch == ')')
            {
                stack.pop();
                continue;
            }
        }

        stack.push(ch);
    }

    return stack.size() == 0;
}