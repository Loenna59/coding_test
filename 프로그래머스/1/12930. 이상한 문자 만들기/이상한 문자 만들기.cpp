#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int current_index = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            answer.push_back(' ');
            current_index = 0;
            continue;
        }

        answer.push_back(current_index & 1? tolower(s[i]) : toupper(s[i]));
        current_index++;
    }

    return answer;
}