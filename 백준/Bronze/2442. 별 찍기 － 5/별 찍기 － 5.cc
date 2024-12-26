#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    int total_size = N * 2 - 1;

    for (int i = 1; i <= N; i++)
    {
        int count = i * 2 - 1;
        int blank_count = N - i;
        for (int j = 1; j <= total_size; j++)
        {
            if (j <= blank_count)
            {
                std::cout << " ";
                continue;
            }

            if (j > total_size - blank_count)
            {
                continue;
            }
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}