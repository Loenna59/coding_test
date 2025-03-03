#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;

    std::cin >> t;

    std::vector<long> answers(t);

    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;

        if (n < 4)
        {
            answers[i] = 1;
            continue;
        }
        
        if (n < 6)
        {
            answers[i] = 2;
            continue;
        }

        long* p = new long[n + 1]{0};

        p[1] = 1;
        p[2] = 1;
        p[3] = 1;
        p[4] = 2;
        p[5] = 2;

        for (int x = 6; x <= n; x++)
        {
            p[x] = p[x - 5] + p[x - 1];
        }

        answers[i] = p[n];

        delete[] p;
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