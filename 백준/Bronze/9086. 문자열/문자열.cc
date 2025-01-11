#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    
    std::string* str = new std::string[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }
        std::cout << *str[i].begin() << *str[i].rbegin();
    }

    return 0;
}