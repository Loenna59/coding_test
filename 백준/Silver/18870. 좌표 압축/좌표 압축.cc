#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main()
{
    long n;
    std::cin >> n;

    std::vector<long long> x(n);

    for (long i = 0; i < n; i++)
    {
        std::cin >> x[i];
    }

    std::vector<long long> achieve(x.begin(), x.end());
    std::sort(achieve.begin(), achieve.end());
    auto it = std::unique(achieve.begin(), achieve.end());
    achieve.erase(it, achieve.end());

    std::unordered_map<long long, int> map;

    int index = 0;
    for (long long a : achieve)
    {
        map.insert({a, index});
        index++;
    }

    for (long i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << " ";
        }
        std::cout << map[x[i]];
    }

    return 0;
}