#include <iostream>
#include <vector>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;

    std::cin >> t;

   int dp[31][31] = {0};

    // 이항계수 https://ko.wikipedia.org/wiki/%EC%9D%B4%ED%95%AD_%EA%B3%84%EC%88%98
    for (int i = 0; i < 31; i++) 
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
        
        for (int j = 1; j < i; j++) 
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    std::vector<long long> answers(t);

    for (int i = 0; i < t; i++)
    {
        int n;
        int m;

        std::cin >> n >> m;

        answers[i] = dp[m][n];
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