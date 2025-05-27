#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;

    long long min = 1000000;
    long long max = 0;

    for (int i = 0; i < n; i++)
    {
        long long num;

        std::cin >> num;

        if (min > num)
        {
            min = num;
        }

        if (max < num)
        {
            max = num;
        }
    }

    std::cout << min * max;
    
    return 0;
}
