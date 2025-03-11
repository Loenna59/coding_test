#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int** grid, std::set<std::pair<int, int>>& visited, int x, int y, int m, int n)
{
    std::queue<std::pair<int, int>> q;
   
    visited.insert({x, y});
    q.push({x, y});

    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = current_x + dx[i];
            int y = current_y + dy[i];

            if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
            {
               if (visited.find({x, y}) == visited.end())
               {
                    visited.insert({x, y});
                    q.push({x, y});
               }
            }
        }
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    int* counts = new int[t]{0};
  
    for (int next = 0; next < t; next++)
    {
        int m;
        int n;
        int k;

        scanf("%d %d %d", &m, &n, &k);

        int** grid = new int*[n];

        for (int a = 0; a < n; a++)
        {
            grid[a] = new int[m]{0};
        }

        for (int j = 0; j < k; j++)
        {
            int x;
            int y;

            scanf("%d %d", &x, &y);

            grid[y][x] = 1;
        }

        std::set<std::pair<int, int>> visited; // 한 번이라도 방문했는지 여부

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited.find({i, j}) == visited.end())
                {
                    bfs(grid, visited, i, j, m, n);
                    counts[next]++;
                }
            }
        }

        for (int a = 0; a < n; a++)
        {
            delete[] grid[a];
        }
        delete[] grid;
    }

    for (int i = 0; i < t; i++)
    {
        if (i > 0)
        {
            printf("\n");
        }

        printf("%d", counts[i]);
    }

    delete[] counts;

    return 0;
}