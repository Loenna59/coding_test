#include <cstdio>

int main()
{
    // 가로 길이가 n일 때 가능한 방법의 수 => f[n];
    // 1 * 2, 2 * 1로 배치할 수 있음
    // 1 * 2 세로로 배치하는 경우의 수 -> f[n - 1]
    // 2 * 1 가로로 배치하는 경우의 수 -> f[n - 2]
    // def) f[n] = f[n - 1] + f[n - 2]
    
    int n;
    scanf("%d", &n);

    int* dp = new int[n + 1];

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp [i - 2]) % 10007;
    }

    printf("%d", dp[n]);

    delete[] dp;

    return 0;
}