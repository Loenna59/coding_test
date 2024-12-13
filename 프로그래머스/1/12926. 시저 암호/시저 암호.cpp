#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if (ch == ' ')
        {
            answer.push_back(ch);
            continue;
        }


        if (tolower(ch) + n > 'z')
        {
            answer.push_back(ch + (n % 26) - 26);
            continue;
        }

        answer.push_back(ch + n);
    }
    
    return answer;
}