#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int k;
    
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> items(n);
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> items[i].first >> items[i].second; // weight, value
    }

    std::vector<int> dp(k + 1, 0);

    for (const std::pair<int, int>& pair : items)
    {
        int weight = pair.first;
        int value = pair.second;

        for (int j = k; j >= weight; --j)
        {
            dp[j] = std::max(dp[j], dp[j - weight] + value);
        }
    }

    std::cout << dp[k] << '\n';
    return 0;
}