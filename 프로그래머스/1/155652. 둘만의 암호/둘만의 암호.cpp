#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    string filtered;
    
    filtered.resize(alphabets.size() - skip.size());
    
    sort(skip.begin(), skip.end());

    set_difference(alphabets.begin(), alphabets.end(), skip.begin(), skip.end(), filtered.begin());

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        int first_of = filtered.find_first_of(ch);
        answer += filtered[(first_of + index) % filtered.size()];
    }
    
    return answer;
}