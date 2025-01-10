#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    
    long long result = 1;

    for (int i = x; i >= 2; --i)
    {
        result *= i;
    }

    std::cout << result;
}