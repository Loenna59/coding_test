#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        char ch = *it;
        
        *it = ch >= 'A' && ch <= 'Z'? ch + 32 : ch - 32;
    }

    std::cout << str;

    return 0;
}