#include <iostream>
#include <iomanip>

int main()
{
    std::time_t now = std::time(0);
    std::cout << std::put_time(std::gmtime(&now), "%Y-%m-%d");
}