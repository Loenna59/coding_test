#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    const vector<string> week_array({"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"});
    const vector<int> days_of_month({31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});

    int days = b;

    for (int i = 0; i < a - 1; i++)
    {
        days += days_of_month[i];
    }

    answer = week_array[(days - 1) % 7];

    return answer;
}