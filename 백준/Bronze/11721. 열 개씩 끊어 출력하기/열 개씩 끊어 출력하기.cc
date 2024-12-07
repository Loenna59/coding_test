#include <iostream>
#include <string>

int main()
{
    std::string input;

    std::cin >> input;
    
    for (int i = 0; i < input.length(); i = i + 10)
    {
        std::string sub_str = input.substr(i, 10);
        std::cout << sub_str << std::endl;
    }
    
    return 0;
}