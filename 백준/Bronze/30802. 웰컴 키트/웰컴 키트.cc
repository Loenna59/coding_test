#include <iostream>

int main()
{
    long long n;
    long long sizes[6];
    long long t;
    long long p;
    long long result_t = 0;

    std::cin >> n;
    for (int i = 0; i < 6; i++)
    {
        std::cin >> sizes[i];
    }
    std::cin >> t >> p;

    for (int i = 0; i < 6; i++)
    {
        result_t += (sizes[i] / t);
        if (sizes[i] % t > 0)
        {
            ++result_t;
        }
    }

    std::cout << result_t << "\n" << n / p << " " << n % p;
    return 0;
}