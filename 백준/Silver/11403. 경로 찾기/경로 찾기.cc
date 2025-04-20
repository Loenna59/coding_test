#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> graph[i][j];
        }
    }

    // 플로이드-워셜
    // i→k→j 경로가 존재하면 i→j 도달 가능하므로 graph[i][j] = 1
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (graph[i][k] && graph[k][j])
                {
                    graph[i][j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << graph[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}