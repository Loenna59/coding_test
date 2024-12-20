#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    const vector<string> nephew_babbling({ "aya", "ye", "woo", "ma"});

    string prev;
    bool loop = true;

    for (string b : babbling)
    {
        prev.clear();
        loop = true;

        while (!b.empty() && loop)
        {
           auto str_it = find_if(nephew_babbling.begin(), nephew_babbling.end(), [b] (string s) { return s[0] == b[0]; });

            if (str_it == nephew_babbling.end())
            {
                loop = false;
                break;
            }

            string str = *str_it;

            if (prev == str)
            {
                loop = false;
                break;
            }

            if (b.substr(0, str.size()) != str)
            {
                loop = false;
                break;
            }

            prev = str;

            b.erase(b.begin(), b.begin() + str.size());
        }

        if (b.empty())
        {
            answer++;
        }
        
    }

    return answer;
}