#include <iostream>

int main()
{
    int x;
    int y;
    
    std::cin >> x >> y;

    if ((x * 12) % 360 == y)
    {
        std::cout << "O";
    }
    else
    {
        std::cout << "X";
    }

    return 0;
}
