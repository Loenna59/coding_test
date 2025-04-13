#include <iostream>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    int n;

    std::cin >> m >> n;

    long sum = 0;
    int min = -1;
    
    for (int i = m; i <= n; i++)
    {
        if (i < 2) continue;
        
        bool composite = false;

        for (int x = 2; x <= std::sqrt(i); x++)
        {
            if (i % x == 0)
            {
                composite = true;
                break;
            }
        }

        if (composite)
        {
            continue;
        }

        sum += i;
        
        if (min < 0)
        {
            min = i;
        }
    }

    if (min < 0)
    {
        std::cout << min;
    }
    else
    {
        std::cout << sum << "\n" << min;
    }

    return 0;
}