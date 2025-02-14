#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> answers;

    while (true)
    {
        string str;
        getline(cin, str);

        if (str.size() < 2 && str[0] == '.')
        {
            break;
        }

        stack<char> brackets; //대괄호
        
        for (int i = 0, size = str.size(); i < size; i++)
        {
            char ch = str[i];

            switch (ch)
            {
            case ')':
                if (brackets.size() > 0 && brackets.top() == '(')
                {
                    brackets.pop();
                }
                else
                {
                    brackets.push(ch);
                    break;
                }
                break;
            case ']':
                if (brackets.size() > 0 && brackets.top() == '[')
                {
                    brackets.pop();
                }
                else
                {
                    brackets.push(ch);
                    break;
                }
                break;
            case '(':
            case '[':
                brackets.push(ch);
                break;
            default:
                break;
            }
        }

        answers.push_back(brackets.empty());
    }

    for (int i = 0, count = answers.size(); i < count; i++)
    {
        if (i > 0)
        {
            cout << "\n";
        }

        cout << (answers[i]? "yes" : "no");
    }

    return 0;
}