#include <iostream>
#include <string>

int main() 
{
    std::string streams[100] {"\0"};
    int index = 0;

    while (index < 100)
    {
        getline(std::cin, streams[index]);
        if (streams[index] == "\0")
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