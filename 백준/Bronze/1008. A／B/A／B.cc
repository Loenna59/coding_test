#include <iostream>

int main()
{
    int a;
    int b;

    std::cin >> a >> b;
    std::cout.precision(sizeof(long double));
    std::cout << a / (double)b;
}