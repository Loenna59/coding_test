#include <iostream>

int main()
{
    int x;

    std::cin >> x;
    std::cout << ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
}