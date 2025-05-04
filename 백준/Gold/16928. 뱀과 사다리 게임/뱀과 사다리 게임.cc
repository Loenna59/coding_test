#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

int bfs(const std::unordered_map<int, int>& teleport)
{
    std::vector<bool> visited(101, false); // 1 ~ 100
    std::queue<std::pair<int, int>> q;     // (현재 위치, 턴 수)
    
    q.push({1, 0});
    
    visited[1] = true;

    while (!q.empty())
    {
        auto [pos, turn] = q.front();
        q.pop();

        if (pos == 100)
        {
            return turn;
        }

        for (int dice = 1; dice <= 6; dice++)
        {
            int next = pos + dice;
            if (next > 100)
                continue;

            // 사다리/뱀 존재하면 이동
            if (teleport.find(next) != teleport.end())
            {
                next = teleport.at(next);
            }

            if (!visited[next])
            {
                visited[next] = true;
                q.push({next, turn + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    int m;

    std::cin >> n >> m;

    std::unordered_map<int, int> teleport;

    for (int i = 0; i < n + m; i++)
    {
        int from;
        int to;

        std::cin >> from >> to;

        teleport[from] = to;
    }

    std::cout << bfs(teleport) << '\n';

    return 0;
}