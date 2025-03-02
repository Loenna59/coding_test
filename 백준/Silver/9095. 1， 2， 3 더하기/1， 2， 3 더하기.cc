#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    
    std::cin >> t;

    std::vector<int> answers(t);

    for (int i = 0; i < t; i++)
    {
        int n;

        std::cin >> n;

        int* dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = 1; // 1
        dp[2] = 2; // 1 + 1, 2
        dp[3] = 4; // 1 + 1 + 1, 1 + 2, 2 + 1, 3

        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        answers[i] = dp[n];

        delete[] dp;
    }

    for (int i = 0; i < t; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }

        std::cout << answers[i];
    }

    return 0;
}