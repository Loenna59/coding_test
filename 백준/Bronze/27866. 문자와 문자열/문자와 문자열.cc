#include <iostream>
#include <string>

int main()
{
    std::string str;
    int index;

    std::cin >> str;
    std::cin >> index;

    std::cout << str.substr(index - 1, 1);

    return 0;
}