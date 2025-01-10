#include <iostream>

int main()
{
    long long x;
    long long y;

    std::cin >> x >> y;

    if (x < y)
    {
        std::cout << y - x;
    }
    else
    {
        std::cout << x - y;
    }
}