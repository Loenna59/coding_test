#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;

    queue<int> q;
    queue<int> answers;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        for (int i = 0; i < k; i++)
        {
            int num = q.front();
            q.pop();
            
            if (i == k - 1)
            {
                answers.push(num);
                continue;
            }

            q.push(num);
        }
    }

    cout << "<";

    while (!answers.empty())
    {
        int num = answers.front();

        if (answers.size() < n)
        {
            cout << ", ";
        }

        cout << num;

        answers.pop();
    }

    cout << ">";
    
    

    return 0;
}