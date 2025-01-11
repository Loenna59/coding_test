#include <iostream>

int main()
{
    int n; 

    std::cin >> n;

    int* numbers = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

    int v;
    int result = 0;

    std::cin >> v;

    for (int i = 0; i < n; i++)
    {
        result += v == numbers[i];
    }

    std::cout << result;

    delete numbers;

    return 0;
}