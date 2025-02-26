#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;

    scanf("%d", &t);

    std::vector<int[2]> answers(t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        int** dp = new int*[n + 1];

        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[2];
        }

        if (n == 0)
        {
            answers[i][0] = 1;
            answers[i][1] = 0;

            continue;
        }

        if (n == 1)
        {
            answers[i][0] = 0;
            answers[i][1] = 1;

            continue;
        }

        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = 1;

        for (int x = 2; x <= n; x++)
        {
            dp[x][0] = dp[x - 1][0] + dp[x - 2][0];
            dp[x][1] = dp[x - 1][1] + dp[x - 2][1];
        }

        answers[i][0] = dp[n][0];
        answers[i][1] = dp[n][1];
    }

    for (int i = 0; i < t; i++)
    {
        if (i > 0)
        {
            printf("\n");
        }

        printf("%d %d", answers[i][0], answers[i][1]);
    }

    return 0;
}