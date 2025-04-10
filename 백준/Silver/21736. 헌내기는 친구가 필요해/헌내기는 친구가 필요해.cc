#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>

int dfs(std::unordered_map<int, std::vector<int>> graph, int start, std::set<int> people)
{
    std::stack<int> s;
    std::set<int> visited;

    int visit_count = 0;
    
    s.push(start);

    while (!s.empty())
    {
        int index = s.top();
        s.pop();

        if (visited.find(index) == visited.end())
        {
            visited.insert(index);

            if (people.find(index) != people.end())
            {
                visit_count++;
            }

            std::sort(graph[index].rbegin(), graph[index].rend());

            for (int e : graph[index])
            {
                if (visited.find(e) == visited.end())
                {
                    s.push(e);
                }
            }
        }
    }

    int people_count = people.size();

    return std::min(people_count, visit_count);
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    int m;

    std::cin >> n >> m;

    std::vector<std::vector<char>> inputs(n);
    std::unordered_map<int, std::vector<int>> graph;
    std::set<int> people;


    int start = -1;

    for (int y = 0; y < n; y++)
    {
        inputs[y] = std::vector<char>(m);

        for(int x = 0; x < m; x++)
        {
            std::cin >> inputs[y][x];
        }
    }

    for (int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            char input = inputs[y][x];
            
            if (input == 'X')
            {
                continue;
            }

            int index = y * m + x;

            if (input == 'I')
            {
                start = index;
            }
            else if (input == 'P')
            {
                people.insert(index);
            }
            
            if (y > 0 && inputs[y - 1][x] != 'X')
            {
                graph[index].push_back(index - m);
                graph[index - m].push_back(index);
            }

            if (x > 0 && inputs[y][x - 1] != 'X')
            {
                graph[index].push_back(index - 1);
                graph[index - 1].push_back(index);
            }

        }
    }

    if (start < 0)
    {
        std::cout << "TT";
        return 0;
    }

    int answer = dfs(graph, start, people);

    if (answer > 0)
    {
        std::cout << answer;
    }
    else
    {
        std::cout << "TT";
    }

    return 0;
}