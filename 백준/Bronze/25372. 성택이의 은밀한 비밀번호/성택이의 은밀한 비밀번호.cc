#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;

    std::cin >> n;

    std::vector<std::string> answers(n);

    for (int i = 0; i < n; i++)
    {
        std::string str;

        std::cin >> str;

        answers[i] = str.size() >= 6 && str.size() <= 9? "yes" : "no";
    }

    for (int i = 0; i < n; i ++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }
        std::cout << answers[i];
    }

    return 0;
}