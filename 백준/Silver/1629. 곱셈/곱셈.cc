#include <iostream>

long long pow_mod(long long a, long long b, long long c)
{
    if (b == 0)
    {
        return 1;
    }

    long long half = pow_mod(a, b / 2, c);
    long long result = (half * half) % c;

    if (b % 2 == 1)
    {
        result = (result * a) % c;
    }

    return result;
}

int main()
{
    long long a;
    long long b;
    long long c;

    std::cin >> a >> b >> c;

    std::cout << pow_mod(a, b, c);

    return 0;
}