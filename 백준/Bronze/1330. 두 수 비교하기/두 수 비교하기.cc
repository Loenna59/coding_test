#include <iostream>

int main()
{
    long a;
    long b;

    std::cin >> a >> b;
    
    if (a > b)
    {
        std::cout << ">";
    }
    else
    if (a < b)
    {
        std::cout << "<";
    }
    else
    {
        std::cout << "==";
    }
}