#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> days_array = vector<int> { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<string> week = vector<string> {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int month;
    int day;

    cin >> month >> day;
    
    if (month > 1)
    {
        for (int i = 0; i < month - 1; i++)
        {
            day += days_array[i];
        }
    }

    cout << week[(day - 1) % 7];

    return 0;
}