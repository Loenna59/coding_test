#include <iostream>
#include <set>

int main()
{
    std::set<int> set;

    for (int i = 0; i < 10; i++)
    {
        int n;
        std::cin >> n;

        set.insert(n % 42);
    }

    std::cout << set.size();

    return 0;
}