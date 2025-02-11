#include <iostream>
#include <stack>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    bool* answers = new bool[n];
    
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        
        stack<char> s;

        for (int x = 0, count = input.size(); x < count; x++)
        {
            char ch = input[x];

            if (!s.empty())
            {
                if (s.top() == '(' && ch == ')')
                {
                    s.pop();
                    continue;
                }
            }

            s.push(ch);
        }

        answers[i] = s.empty();
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << "\n";
        }

        cout << (answers[i]? "YES" : "NO");
    }

    delete[] answers;

    return 0;
}