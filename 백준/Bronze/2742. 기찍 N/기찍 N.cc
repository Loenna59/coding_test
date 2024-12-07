#include <iostream>

int main()
{
    int input;

    std::cin >> input;

    for (int i = input; i > 0; i--)
    {
        std::cout << i << "\n"; //std::endl은 시간초과
    }
    
    return 0;
}