#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int same = 0;
    int other = 0;
    char x = '\0';

    for (char ch : s)
    {
        if (x == '\0')
        {
            x = ch;
        }

        if (x == ch)
        {
            same++;
        }
        else
        {
            other++;
        }

        if (same == other)
        {
            answer++;
            same = 0;
            other = 0;
            x = '\0';
        }
    }

    if (same != other)
    {
        answer++;
    }
    
    return answer;
}