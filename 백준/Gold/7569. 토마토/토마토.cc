#include <cstdio>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

const int dz[6] = {0, 0, 0, 0, -1, 1};
const int dy[6] = {-1, 1, 0, 0, 0, 0};
const int dx[6] = {0, 0, -1, 1, 0, 0};

int bfs(std::vector<std::vector<std::vector<int>>>& grid, int h, int n, int m)
{
    std::queue<std::pair<std::tuple<int, int, int>, int>> q;
    std::set<std::tuple<int, int, int>> visited;

    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (grid[z][y][x] == 1)
                {
                    q.push({std::make_tuple(z, y, x), 0});
                    visited.insert(std::make_tuple(z, y, x));
                }
            }
        }
    }

    int max_day = 0;

    while (!q.empty())
    {
        auto [pos, day] = q.front();
        q.pop();

        max_day = std::max(max_day, day);

        int z, y, x;
        std::tie(z, y, x) = pos;

        for (int i = 0; i < 6; i++)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nz >= 0 && nz < h && ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (grid[nz][ny][nx] == 0)
                {
                    auto next = std::make_tuple(nz, ny, nx);

                    if (visited.find(next) == visited.end())
                    {
                        visited.insert(next);
                        grid[nz][ny][nx] = 1;
                        q.push({next, day + 1});
                    }
                }
            }
        }
    }

    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (grid[z][y][x] == 0)
                {
                    return -1;
                }
            }
        }
    }

    return max_day;
}

int main()
{
    int m, n, h;
    scanf("%d %d %d", &m, &n, &h);

    std::vector<std::vector<std::vector<int>>> grid(h, std::vector<std::vector<int>>(n, std::vector<int>(m)));

    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                scanf("%d", &grid[z][y][x]);
            }
        }
    }

    int result = bfs(grid, h, n, m);
    
    printf("%d\n", result);

    return 0;
}
