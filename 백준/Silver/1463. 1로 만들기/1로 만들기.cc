#include <cstdio>
#include <algorithm>

int main()
{
    int x;

    scanf("%d", &x);

    int count = 0;

    int* dp = new int[x + 1]{0};
    
    for (int i = 2; i <= x; i++)
    {
        // 1빼는 경우: 모든 숫자에 다 해당
        dp[i] = dp[i - 1] + 1;

        // 2로 나눌 수 있을을 경우
        if (i % 2 == 0)
        {
            dp[i] = std::min(dp[i], dp[i / 2] + 1);
        }

        // 3으로 나눌 수 있을 경우
        if (i % 3 == 0)
        {
            dp[i] = std::min(dp[i], dp[i / 3] + 1);
        }
    }

    printf("%d", dp[x]);

    return 0;
}