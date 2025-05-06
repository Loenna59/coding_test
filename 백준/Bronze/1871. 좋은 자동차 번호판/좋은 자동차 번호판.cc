#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;

    std::vector<std::string> answers(n);

    for (int i = 0; i < n; i++)
    {
        std::string str;
        std::cin >> str;

        int price = (str[0] - 'A') * 26 * 26;
        price += (str[1] - 'A') * 26;
        price += (str[2] - 'A');

        price -= std::stoi(str.substr(4));
        
        answers[i] = std::abs(price) > 100? "not nice" : "nice";
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }

        std::cout << answers[i];
    }

    return 0;
}
