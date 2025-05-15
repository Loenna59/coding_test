#include <iostream>
#include <string>
#include <algorithm>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string n;
    std::cin >> n;

    std::sort(n.rbegin(), n.rend());

    std::cout << n;

    return 0;
}