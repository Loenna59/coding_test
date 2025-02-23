#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    int m;

    std::cin >> n >> m;

    std::vector<std::string> dic(n);
    std::unordered_map<std::string, int> indexes;

    for (int i = 0; i < n; i++)
    {
        std::cin >> dic[i];
        indexes[dic[i]] = i + 1;
    }

    for (int i = 0; i < m; i++)
    {
        std::string str;
        std::cin >> str;

        if (i > 0)
        {
            std::cout << "\n";
        }

        if (std::isdigit(str[0]))
        {
            int num = std::stol(str);
            std::cout << dic[num - 1];
            continue;
        }
        
        std::cout << indexes[str];
    }

    return 0;
}