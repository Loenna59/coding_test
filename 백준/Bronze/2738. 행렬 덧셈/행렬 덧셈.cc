#include <iostream>

int main()
{
    int n;
    int m;

    std::cin >> n >> m;

    int matrix = n * m;

    int* a = new int[matrix];
    int* b = new int[matrix];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[j + i * m];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> b[j + i * m];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }
        for (int j = 0; j < m; j++)
        {
            if (j > 0)
            {
                std::cout << " ";
            }
            std::cout << a[j + i * m] + b[j + i * m];
        }
    }

    delete a;
    delete b;

    return 0;
}