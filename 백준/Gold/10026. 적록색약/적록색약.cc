#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int dx[4] { 0, 0, 1, -1 };
const int dy[4] { 1, -1, 0, 0 };

bool color_equals(char col, char other, bool blindness)
{
    if (blindness)
    {
        if (other == 'B')
        {
            return col == 'B';
        }

        return col == 'R' || col == 'G';
    }

    return col == other;
}

int bfs(std::vector<std::vector<char>> grid, int n, bool blindness)
{
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

    int result = 0;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (visited[y][x])
            {
                continue;
            }

            q.push({y, x});
            visited[y][x] = true;
            char color = grid[y][x];

            result++;

            while (!q.empty())
            {
               auto [cy, cx] = q.front();
               q.pop();
        
               for (int i = 0; i < 4; i++)
               {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
        
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        if (!visited[ny][nx] && color_equals(grid[ny][nx], color, blindness))
                        {
                            visited[ny][nx] = true;
                            q.push({ny, nx});
                        }
                    }
               }
            }
        }
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    std::vector<std::vector<char>> grid(n, std::vector<char>(n));

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            std::cin >> grid[y][x];
        }
    }

    std::cout << bfs(grid, n, false) << " " << bfs(grid, n, true);

    return 0;
}