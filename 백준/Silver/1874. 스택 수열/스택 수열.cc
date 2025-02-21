#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    queue<int> nums;
    vector<char> processes;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        q.push(input);
        nums.push(i + 1);
    }

    stack<int> s;

    while (!q.empty())
    {
        if (!s.empty())
        {
           if (s.top() == q.front())
           {
                s.pop();
                q.pop();
                processes.push_back('-');

                continue;
           }

           if (nums.empty())
           {
                break;
           }
        }

        if (!nums.empty())
        {
            s.push(nums.front());
            nums.pop();
            processes.push_back('+');
        }
    }

    if (q.size() > 0)
    {
        cout << "NO";
        return 0;
    }

    for (int i = 0, count = processes.size(); i < count; i++)
    {
        if (i > 0)
        {
            cout << "\n";
        }
        cout << processes[i];
    }
    
    return 0;
}