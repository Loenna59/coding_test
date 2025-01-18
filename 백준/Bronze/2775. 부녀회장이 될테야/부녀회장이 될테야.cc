#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    int n;

    std::cin >> n;

    std::string answer;

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            answer.append("\n");
        }

        int k; //층
        int n; //호

        std::cin >> k >> n;

        int** dp = new int*[k + 1];

        for (int i = 0; i < k + 1; i++)
        {
            dp[i] = new int[n];
        }

        // 0층의 n호는 n명이 거주
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = i + 1;
        }

        // k층의 n호 거주자 수는 (k-1)층의 1호부터 n호까지 합
        for (int i = 1; i <= k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = dp[0][0];
                    continue;
                }

                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        answer.append(std::to_string(dp[k][n - 1]));
        
        delete[] dp;
    }

    std::cout << answer;

    return 0;
}
