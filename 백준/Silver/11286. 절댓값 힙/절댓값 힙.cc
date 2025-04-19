#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    auto comp = [](int a, int b) {
        if (std::abs(a) != std::abs(b))
        {
            return std::abs(a) > std::abs(b); // 절댓값 기준 작은 값 우선
        }
        return a > b; // 절댓값 같으면 작은 수 우선
    };

    std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                std::cout << "0\n";
            }
            else
            {
                std::cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }

    return 0;
}