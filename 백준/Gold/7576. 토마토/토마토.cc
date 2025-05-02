#include <cstdio>
#include <queue>
#include <vector>

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int bfs(std::vector<std::vector<int>>& grid, int n, int m)
{
    std::queue<std::pair<std::pair<int, int>, int>> q;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (grid[y][x] == 1)
            {
                std::pair<int, int> p = std::make_pair(y, x);
                q.push({p, 0});
            }
        }
    }

    int max_day = 0;

    while (!q.empty())
    {
        auto [pos, day] = q.front();
        q.pop();

        max_day = std::max(max_day, day);

        int y;
        int x;
        
        y = pos.first;
        x = pos.second;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                if (grid[ny][nx] == 0)
                {
                    grid[ny][nx] = 1;
                    q.push({std::make_pair(ny, nx), day + 1});
                }
            }
        }
    }


    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (grid[y][x] == 0)
            {
                return -1;
            }
        }
    }

    return max_day;
}

int main()
{
    int m; 
    int n;
    scanf("%d %d", &m, &n);

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            scanf("%d", &grid[y][x]);
        }
    }

    int result = bfs(grid, n, m);
    
    printf("%d\n", result);

    return 0;
}
