#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(std::vector<std::vector<int>>& grid, int x, int y, int m, int n)
{
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> distances(n, std::vector<int>(m, -1)); // 방문하지 못한 곳은 -1로 초기화

    q.push({x, y});
    distances[y][x] = 0;

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j > 0)
            {
                printf(" ");
            }

            if (grid[i][j] == 0)
            {
                printf("0");
            }
            else
            {
                printf("%d", distances[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int m;
    int n;

    scanf("%d %d", &n, &m);

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));

    int start_x = -1;
    int start_y = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &grid[i][j]);

            if (grid[i][j] == 2)
            {
                start_x = j;
                start_y = i;
            }
        }
    }

    bfs(grid, start_x, start_y, m, n);

    return 0;
}