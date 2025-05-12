#include <iostream>
#include <queue>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a;
    long long b;
    
    std::cin >> a >> b;

    std::queue<std::pair<long long, int>> q;
    
    q.push({a, 1});

    while (!q.empty()) 
    {
        auto [current, count] = q.front();
        q.pop();

        if (current == b) 
        {
            std::cout << count << "\n";
            return 0;
        }

       
        if (current * 2 <= b)
        {
            q.push({current * 2, count + 1});
        }

        if (current * 10 + 1 <= b)
        {
            q.push({current * 10 + 1, count + 1});
        }
    }

    std::cout << "-1";

    return 0;
}