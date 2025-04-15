#include <iostream>
#include <vector>
#include <numeric>

const int NONE = 1e9;

// 플루이드-워셜 알고리즘
// 두 개의 인자 v와 weight을 받고, 최단 거리가 저장된 2차원 정수 벡터 반환 (dp)
std::vector<std::vector<int>> floyd(int v, std::vector<std::vector<int>> weight)
{
    std::vector<std::vector<int>> distance(v, std::vector<int>(v, NONE));

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            distance[i][j] = weight[i][j];
        }

        distance[i][i] = 0; // 자신의 거리값은 0 
    }

    for (int mid = 0; mid < v; mid++)
    {
        for (int start = 0; start < v; start++)
        {
            for (int end = 0; end < v; end++)
            {
                if (distance[start][end] > distance[start][mid] + distance[mid][end])
                {
                    distance[start][end] = distance[start][mid] + distance[mid][end];
                }
            }
        }
    }

    return distance;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int m;

    std::cin >> n >> m;

    std::vector<std::vector<int>> weight(n, std::vector<int>(n, NONE));

    for (int i = 0; i < m; i++)
    {
        int u;
        int v;

        std::cin >> u >> v;

        u--;
        v--;

        weight[u][v] = 1;
        weight[v][u] = 1; // 양방 처리
    }

    std::vector<std::vector<int>> distance = floyd(n, weight);

    int min_sum = NONE;
    int min_index = -1;

    for (int i = 0; i < n; i++)
    {
        int sum = std::accumulate(distance[i].begin(), distance[i].end(), 0);

        if (min_sum > sum)
        {
            min_sum = sum;
            min_index = i;
        }
    }

    std::cout << min_index + 1;

    return 0;
}