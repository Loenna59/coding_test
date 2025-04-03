#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::string doctor;

    std::cin >> str >> doctor;
    
    if (str.find(doctor) == std::string::npos)
    {
        std::cout << "no";
        return 0;
    }

    std::cout << "go";

    return 0;
}