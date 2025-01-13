#include <iostream>
#include <cmath>

int main()
{
    int n;
    std::cin >> n;

    int prime_count = 0;

    for (int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;

        int count = 0;
        for (int x = 1; x <= sqrt(input); x++)
        {
            if (input > 1 && input % x == 0)
            {
                count++;
            }
        }

        if (count == 1)
        {
            prime_count++;
        }
    }

    std::cout << prime_count;
}