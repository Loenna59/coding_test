#include <cstdio>
#include <algorithm>

int main()
{
    // min(dp[i - j^2] + 1)

    int n;

    scanf("%d", &n);

    int* dp = new int[n + 1];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2; // 1 + 1 << 2개
    dp[3] = 3;
    dp[4] = 1;
    dp[5] = 2;

    for (int i = 6; i <= n; i++)
    {
        dp[i] = 4;
        for (int j = 0; (j * j) <= i; j++)
        {
            dp[i] = std::min(dp[i - j * j] + 1, dp[i]);       
        }
    }

    printf("%d", dp[n]);

    return 0;
}