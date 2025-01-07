#include <iostream>
#include <string>

int main() 
{
    std::string streams[100] {""};
    int index = 0;

    while (index < 100)
    {
        getline(std::cin, streams[index]);

        if (std::cin.fail())
        {
            break;
        }

        if (index > 0)
        {
            std::cout << "\n";
        }
        std::cout << streams[index];
        index++;
    }

    return 0;
}