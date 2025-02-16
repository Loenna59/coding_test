#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    cin >> k;

    vector<int> answers;

    for (int i = 0; i < k; i++)
    {
        int n;
        int m;

        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> priority_q;

        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            q.push(make_pair(i, input));
            priority_q.push(input);
        }

        int order = 0;

        while (!q.empty()) 
        {
            int index = q.front().first;
            int priority = q.front().second;
            q.pop();

            if (priority == priority_q.top()) 
            { 
                order++;
                priority_q.pop();
                if (index == m) 
                { 
                    answers.push_back(order);
                    break;
                }

                continue;
            } 
           
            q.push({index, priority}); 
        }

    }

    for (int i = 0, count = answers.size(); i < count; i++)
    {
        if (i > 0)
        {
            cout << "\n";
        }

        cout << answers[i];
    }

    return 0;
}