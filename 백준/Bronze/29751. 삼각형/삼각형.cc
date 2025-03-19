#include <iostream>

int main()
{    
    int w;
    int h;

    std::cin >> w >> h;

    std::cout.precision(1);

    std::cout << std::fixed << w * h * 0.5;

    return 0;
}