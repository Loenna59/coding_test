#include <iostream>

int main()
{
    int hour;
    int minute;

    std::cin >> hour >> minute;

    if (minute < 45)
    {
        if (hour == 0)
        {
            hour = 24;
        }

        hour -= 1;
        minute += 60;
    }

    std::cout << hour << " " << minute - 45;

    return 0;
}