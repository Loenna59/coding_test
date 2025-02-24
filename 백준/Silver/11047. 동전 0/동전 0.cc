#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; // 동전의 종류 개수
    int k; // 만들자하는 가치

    std::cin >> n >> k;

    std::vector<int> values(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }

    int count = k / values.back();
    int remain = k % values.back();
    
    if (remain == 0)
    {
        std::cout << count;

        return 0;
    }

    int index = values.size() - 1;

    while (index >= 0)
    {
        index--;

        count += remain / values[index];
        remain = remain % values[index];

        if (remain == 0)
        {
            break;
        }
    }

    std::cout << count;

    return 0;
}