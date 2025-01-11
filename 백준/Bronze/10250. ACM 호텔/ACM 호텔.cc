#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

int main()
{
    int t;
    std::cin >> t;

    std::stringstream* rooms = new std::stringstream[t];

    for (int i = 0; i < t; i++)
    {
        long h;
        long w;
        long n;

        std::cin >> h >> w >> n;

        long floor = (n - 1) % h + 1;
        long room = (n / h);
        if (n % h > 0)
        {
            room++;
        }

        rooms[i] << floor << std::setw(2) << std::setfill('0') << room;
    }

    
    for (int i = 0; i < t; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }
        std::cout << rooms[i].str();
    }

    return 0;
}