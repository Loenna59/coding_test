#include <iostream>
#include <cstdio>

int main()
{
    long long n;

    std::cin >> n;

    int count_arr[10001] = {0};

    for (long long i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        count_arr[input]++;
    }

    for (int i = 0; i <= 10000; i++)
    {
        if (count_arr[i] > 0)
        {
            for (int j = 0; j < count_arr[i]; j++)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}