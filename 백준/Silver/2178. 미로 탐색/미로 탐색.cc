#include <iostream>
#include <queue>
#include <vector>
#include <string>

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int bfs(std::vector<std::vector<int>>& grid, int m, int n)
{
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> distances(n, std::vector<int>(m, -1)); // 방문하지 못한 곳은 -1로 초기화

    q.push({0, 0});
    distances[0][0] = 1;

    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = current_x + dx[i];
            int y = current_y + dy[i];

            if (x >= 0 && y >= 0 && x < m && y < n && grid[y][x] == 1)
            {
                if (distances[y][x] == -1)
                {
                    distances[y][x] = distances[current_y][current_x] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    return distances[n - 1][m - 1];
}

int main()
{
    int n;
    int m;

    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(n);

    for (int i = 0; i < n; i++)
    {
        std::string line;
        std::cin >> line;

        for (auto& ch : line)
        {
            grid[i].push_back(ch - 48);
        }
    }

    std::cout << bfs(grid, m, n);

    return 0;
}