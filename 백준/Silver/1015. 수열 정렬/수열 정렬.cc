#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;

    // a -> [2] = 0, [3] = 1, [1] = 2

    // 정렬하면? b -> 1, 2, 3

    // a[0] = 2이고 b[1]에 2가 있음 => p[0] = 1
    // a[1] = 3이고 b[2]에 3이 있음 => p[1] = 2
    // a[2] = 1이고 b[0]에 1이 았음 => p[2] = 0

    std::vector<std::pair<int, int>> a(n);

    std::vector<int> p(n);


    for (int i = 0; i < n; i++)
    {
        int num;

        std::cin >> num;
        
        a[i] = std::make_pair(num, i);
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        int index = a[i].second;
        p[index] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << " ";
        }
        std::cout << p[i];
    }
    
    return 0;
}
