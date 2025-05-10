#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;
    std::cin.ignore();

    std::string sentences;
    std::getline(std::cin, sentences);

    if (n <= 25)
    {
        std::cout << sentences;
    }
    else
    {
        for (int i = 12; i < n - 12; i++)
        {
            if (sentences[i] == '.')
            {
                std::cout << sentences.substr(0, 9) << "......" << sentences.substr(n - 10);
                return 0;
            }
        }

        std::cout << sentences.substr(0, 11) << "..." << sentences.substr(n - 11);
    }

    return 0;
}