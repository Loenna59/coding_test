#include <iostream>

int main()
{
    int n; 
    int x;

    std::cin >> n >> x;

    int* numbers = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

    bool append = false;

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] < x)
        {
            if (append)
            {
               std::cout << " ";
            }

            append |= true;
            std::cout << numbers[i];
        }
    }

    delete numbers;

    return 0;
}