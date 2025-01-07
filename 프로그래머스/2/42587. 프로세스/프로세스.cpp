#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> queue;

    for (int i = 0; i < priorities.size(); i++)
    {
        queue.push({i, priorities[i]});
    }

    sort(priorities.rbegin(), priorities.rend());

    while (!queue.empty())
    {
        pair<int, int> proccess = queue.front();
        queue.pop();

        if (proccess.second == priorities[answer])
        {
            if (proccess.first == location)
            {
                return answer + 1;
            }
            
            answer++;
            continue;
        }

        queue.push(proccess);
    }

    return -1;
}