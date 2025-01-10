#include <iostream>

int main()
{
    int x;
    int y;

    std::cin >> x;
    std::cin >> y;

    int Quadrant;

    if (x > 0 && y > 0)
    {
        Quadrant = 1;
    }
    else
    if (x < 0 && y > 0)
    {
        Quadrant = 2;
    }
    else
    if (x < 0 && y < 0)
    {
        Quadrant = 3;
    }
    else
    {
        Quadrant = 4;
    }

    std::cout << Quadrant;
}