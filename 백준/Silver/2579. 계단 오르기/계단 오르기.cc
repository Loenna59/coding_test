#include <cstdio>
#include <algorithm>

int main()
{    
    int n;
    scanf("%d", &n);

    int* stair = new int[n + 1]{0};

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stair[i + 1]);
    }

    int* dp = new int[n + 1];

    if (n < 4)
    {
        switch (n)
        {
        case 1:
            printf("%d", stair[1]);
            break;
        case 2:
            printf("%d", stair[1] + stair[2]);
            break;
        case 3:
            printf("%d", std::max(stair[1] + stair[3], stair[2] + stair[3]));
            break;
        default:
            printf("%d", 0);
            break;
        }

        return 0;
    }
    
    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = std::max(stair[1] + stair[3], stair[2] + stair[3]);

    for (int i = 4; i <= n; i++)
    {
        dp[i] = std::max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
    }

    printf("%d", dp[n]);

    return 0;
}