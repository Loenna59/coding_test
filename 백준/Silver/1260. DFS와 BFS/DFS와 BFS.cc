#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_map>
#include <algorithm>

std::vector<int> dfs(std::unordered_map<int, std::vector<int>> graph, int start)
{
    std::stack<int> s;
    std::set<int> visited;
    std::vector<int> orders;

    s.push(start);

    while (!s.empty())
    {
        int cur_vertex = s.top();
        s.pop();

        if (visited.find(cur_vertex) == visited.end())
        {
            visited.insert(cur_vertex);
            orders.push_back(cur_vertex);

            std::sort(graph[cur_vertex].rbegin(), graph[cur_vertex].rend());

            for (int e : graph[cur_vertex])
            {
                if (visited.find(e) == visited.end())
                {
                    s.push(e);
                }
            }
        }
    }

    return orders;
}

std::vector<int> bfs(std::unordered_map<int, std::vector<int>> graph, int start)
{
    std::queue<int> q;
    std::set<int> visited;
    std::vector<int> orders;

    q.push(start);

    while (!q.empty())
    {
        int cur_vertex = q.front();
        q.pop();

        if (visited.find(cur_vertex) == visited.end())
        {
            visited.insert(cur_vertex);
            orders.push_back(cur_vertex);

            std::sort(graph[cur_vertex].begin(), graph[cur_vertex].end());

            for (int e : graph[cur_vertex])
            {
                if (visited.find(e) == visited.end())
                {
                    q.push(e);
                }
            }
        }
    }

    return orders;
}

int main()
{    
    int n; // vertex
    int m; // edge
    int v; // start

    scanf("%d %d %d", &n, &m, &v);

    std::unordered_map<int, std::vector<int>> graph;

    for (int i = 0; i < m; i++)
    {
        int value1;
        int value2;

        scanf("%d %d", &value1, &value2);

        graph[value1].push_back(value2);
        graph[value2].push_back(value1);
    }

    std::vector<int> dfs_orders = dfs(graph, v);
    std::vector<int> bfs_orders = bfs(graph, v);

    for (int i = 0, count = dfs_orders.size(); i < count; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", dfs_orders[i]);
    }

    printf("\n");

    for (int i = 0, count = bfs_orders.size(); i < count; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", bfs_orders[i]);
    }

    return 0;
}