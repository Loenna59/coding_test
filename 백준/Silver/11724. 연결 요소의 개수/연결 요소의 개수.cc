#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <set>

int bfs(std::unordered_map<int, std::vector<int>> graph, std::set<int>& visited, int start)
{
    std::queue<int> q;
    
    q.push(start);
    
    while (!q.empty())
    {
        int cur_vertex = q.front();
        q.pop();

        if (visited.find(cur_vertex) == visited.end())
        {
            visited.insert(cur_vertex);

            for (int e : graph[cur_vertex])
            {
                if (visited.find(e) == visited.end())
                {        
                    q.push(e);
                }
            }
        }
    }

    return 1;
}

int main()
{
    int n;
    int m;

    std::cin >> n >> m;

    std::unordered_map<int, std::vector<int>> graph;
    
    std::set<int> visited;

    for (int i = 0; i < m; i++)
    {
        int value1;
        int value2;
        
        std::cin >> value1 >> value2;

        graph[value1].push_back(value2);
        graph[value2].push_back(value1);
    }

    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited.find(i) == visited.end())
        {
            answer += bfs(graph, visited, i);
        }
    }

    std::cout << answer;

    return 0;
}