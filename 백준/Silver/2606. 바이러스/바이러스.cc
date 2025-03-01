#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

//BFS 사용
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; // 컴퓨터의 수
    int m; // 네트워크 상에서 직접 연결되어 있는 컴퓨터의 쌍의 수

    std::cin >> n >> m;

    std::unordered_map<int, std::vector<int>> graph;

    for (int i = 0; i < m; i++)
    {
        int value1;
        int value2;

        std::cin >> value1 >> value2;
        
        graph[value1].push_back(value2);
        graph[value2].push_back(value1);
    }

    std::queue<int> q;
    std::set<int> visited;

    q.push(1);
    visited.insert(1);

    while (!q.empty())
    {
        int computer = q.front();
        q.pop();
            
        for (int edge : graph[computer])
        {
            if (visited.find(edge) == visited.end())
            {
                visited.insert(edge);
                q.push(edge);
            }
        }
    }

    std::cout << visited.size() - 1;

    return 0;
}