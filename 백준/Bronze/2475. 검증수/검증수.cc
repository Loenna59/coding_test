#include <iostream>

int main()
{
    int* numbers = new int[5];

    for (int i = 0; i < 5; i++)
    {
        std::cin >> numbers[i];
    }

    long long verify = 0;

    for (int i = 0; i < 5; i++)
    {
        verify += numbers[i] * numbers[i];
    }

    std::cout << verify % 10;

    return 0;
}