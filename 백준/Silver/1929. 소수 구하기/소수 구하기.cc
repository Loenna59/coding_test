#include <iostream>
#include <cmath>

int main()
{
    int min, max;

    std::cin >> min >> max;

    for (int i = min; i <= max; i++)
    {
        int count = 0;

        if (i < 2)
        {
            continue;
        }

        for (int x = 1, len = std::sqrt(i); x <= len; x++)
        {
            if (i % x == 0)
            {
                count++;
            }
        }

        if (count == 1)
        {
            std::cout << i << "\n";
        }
    }

    return 0;
}