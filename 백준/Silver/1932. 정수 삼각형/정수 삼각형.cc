#include <iostream>
#include <algorithm>

int main()
{
    int triangle[501][501];
    int dp[501][501];

    int n;
    
    std::cin >> n;

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x <= y; ++x)
        {
            std::cin >> triangle[y][x];
        }
    }

    dp[0][0] = triangle[0][0];

    for (int y = 1; y < n; ++y)
    {
        for (int x = 0; x <= y; ++x)
        {
            if (x == 0)
                dp[y][x] = dp[y - 1][x] + triangle[y][x];
            else if (x == y)
                dp[y][x] = dp[y - 1][x - 1] + triangle[y][x];
            else
                dp[y][x] = std::max(dp[y - 1][x - 1], dp[y - 1][x]) + triangle[y][x];
        }
    }

    int result = 0;

    for (int x = 0; x < n; ++x)
    {
        result = std::max(result, dp[n - 1][x]);
    }

    std::cout << result << '\n';

    return 0;
}