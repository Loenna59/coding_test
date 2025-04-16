#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::string keyword;

    std::cin >> str >> keyword;

    std::string processed_str;

    for (int i = 0, count = str.size(); i < count; i++)
    {
        if (!isdigit(str[i]))
        {
            processed_str += str[i];
        }
    }

    std::cout << (processed_str.find(keyword) != std::string::npos);
}