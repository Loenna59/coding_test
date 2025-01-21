#include <iostream>
#include <vector>
#include <string>

// 팩토리얼에서 0이 만들어지는 조건은 10 = 2 × 5의 곱이 등장하는 것
// 그런데 2는 5보다 더 자주 등장하므로, 5의 개수만 센다
int main()
{
    int n;
    std::cin >> n;

    if (n < 2)
    {
        std::cout << "0";
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 5; j <= n; j *= 5)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
    }

    std::cout << count;
    
    return 0;
}