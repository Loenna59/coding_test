#include <iostream>
#include <vector>

#define LONG_MAX 2147483647L

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    int m;
    long b;

    std::cin >> n >> m >> b;

    std::vector<std::vector<int>> grid(n);

    for (int i = 0; i < n; i++)
    {
        grid[i] = std::vector<int>(m);

        for (int j = 0; j < m; j++)
        {
            std::cin >> grid[i][j];
        }
    }

    int tallest_height = 0;
    long min_seconds = LONG_MAX;

    for (int h = 0; h <= 256; h++)
    {
        long add = 0;
        long remove = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] > h)
                {
                    remove += (grid[i][j] - h);
                }
                else
                {
                    add += (h - grid[i][j]);
                }
            }
        }

        long inven = b + remove - add;

        if (inven >= 0)
        {
            long seconds = remove * 2 + add;

            if (seconds < 0)
            {
                continue;
            }

            if (seconds < min_seconds || (seconds == min_seconds && h > tallest_height))
            {
                min_seconds = seconds;
                tallest_height = h;
            }
        }
    }

    std::cout << min_seconds << " " << tallest_height;

    return 0;
}