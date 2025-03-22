#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    long long n;
    long long m;

    std::cin >> n >> m;

    std::vector<long long> trees(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> trees[i];
    }

    std::sort(trees.begin(), trees.end());

    long long low = 0;
    long long high = trees[n - 1];

    while (true)
    {
        long long sum = 0;
        long long len = std::floor((low + high) * 0.5);

        for (long long tree : trees)
        {
            if (tree > len)
            {
                sum += tree - len;
            }
        }

        if (low > high)
        {
            std::cout << len;
            return 0;
        }
        
        if (m > sum)
        {
            high = len - 1;
        }
        else if (m < sum)
        {
            low = len + 1;
        }
        else
        {
            std::cout << len;
            return 0;
        }
    }

    return 0;
}