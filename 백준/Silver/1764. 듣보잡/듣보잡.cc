#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; // 듣도 못한 사람의 수
    int m; // 보도 못한 사람의 수

    std::unordered_map<std::string, bool> map;

    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        std::string name;
        std::cin >> name;
        map[name] = true;
    }

    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> q;

    for (int i = 0; i < m; i++)
    {
        std::string name;
        std::cin >> name;
        
        if (map.find(name) != map.end())
        {
           q.push(name);
        }
    }

    int size = q.size();

    std::cout << size;

    while (!q.empty())
    {
        std::cout << "\n" << q.top();
        q.pop();
    }

    return 0;
}