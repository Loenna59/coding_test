#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; // 사람 수

    std::cin >> n;

    std::vector<int> p(n); // 각자의 돈 인출 소요 시간

    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }

    std::sort(p.begin(), p.end());

    int times = 0;

    int* arr = new int[n + 1] {0};

    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i - 1] + p[i - 1];
        times += arr[i];
    }

    std::cout << times;

    delete[] arr;

    return 0;
}