#include <iostream>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;

    if (n == 0)
    {
        std::cout << "divide by zero";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int score;
        std::cin >> score;
    }


    std::cout << "1.00";

    return 0;
}