#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string result;
    vector<string> num_en{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for(int i = 0, len = 0; i < s.size(); i += len)
    {
        int d = s[i] - 48;
        len = 1;
        if (d >= 0 && d < 10)
        {
            result.push_back(s[i]);
            continue;
        }

        string substr = s.substr(i, 3);

        for (int x = 0; x < num_en.size(); x++)
        {
            size_t found = num_en[x].find(substr);
            if (found != string::npos)
            {
                result.push_back(x + 48);
                len = num_en[x].size();
            }
        }
    }

    answer = stoi(result);
    
    return answer;
}