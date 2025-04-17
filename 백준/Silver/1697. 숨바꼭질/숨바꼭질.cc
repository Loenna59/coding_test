#include <iostream>
#include <queue>
#include <vector>

int bfs(int start, int end)
{
    std::queue<std::pair<int, int>> q; // 현재 위치, 시간
    std::vector<bool> visited(100001, false);

    q.push({start, 0});
    visited[start] = true;

    while (!q.empty())
    {
        std::pair<int, int> current = q.front();
        q.pop();

        int index = current.first;

        if (index == end)
        {
            return current.second;
        }

        for (int next : { index - 1, index + 1, index * 2 })
        {
            if (next >= 0 && next <= 100000 && !visited[next])
            {
                visited[index] = true;
                q.push({next, current.second + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    int k;

    std::cin >> n >> k;

    std::cout << bfs(n, k);

    return 0;
}