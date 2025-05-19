#include <iostream>

using namespace std;

int days_in_month[13] =
{
    0,
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_days(int y, int m, int d)
{
    int total = 0;

    for (int i = 1; i < y; i++)
    {
        total += is_leap_year(i) ? 366 : 365;
    }

    for (int i = 1; i < m; i++)
    {
        total += days_in_month[i];
        
        if (i == 2 && is_leap_year(y))
        {
            total += 1;
        }
    }

    total += d;

    return total;
}

int main()
{
    int y1;
    int m1;
    int d1;

    int y2;
    int m2;
    int d2;

    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;

    if (y2 - y1 > 1000 || (y2 - y1 == 1000 && (m2 > m1 || (m2 == m1 && d2 >= d1))))
    {
        cout << "gg\n";
    }
    else
    {
        int days1 = get_days(y1, m1, d1);
        int days2 = get_days(y2, m2, d2);
        cout << "D-" << days2 - days1 << '\n';
    }

    return 0;
}