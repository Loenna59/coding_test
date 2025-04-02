#include <iostream>
#include <ctime>

int main()
{
    time_t t = time(nullptr);

    tm* utc_t = gmtime(&t);

    std::cout << utc_t->tm_year + 1900 << "\n";

    std::cout.width(2);
    std::cout.fill('0');
    std::cout << utc_t->tm_mon + 1 << "\n";

    std::cout.width(2);
    std::cout.fill('0');
    std::cout << utc_t->tm_mday;

    return 0;
}