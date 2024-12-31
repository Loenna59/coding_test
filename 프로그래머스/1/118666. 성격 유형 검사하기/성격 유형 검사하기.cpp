#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    vector<string> p({"RT", "CF", "JM", "AN"});
    vector<int> scores{ 0, 0, 0, 0 };

    for (int i = 0; i < choices.size(); i++)
    {
        string s = survey[i];
        int choice = choices[i];

        if (any_of(s.begin(), s.end(), [](char ch) { return ch == 'R'; }))
        {
            if (*s.begin() == 'R')
            {
                scores[0] += choice - 4;
                continue;
            }

            scores[0] += 4 - choice;
            continue;
        }

        if (any_of(s.begin(), s.end(), [](char ch) { return ch == 'C'; }))
        {
            if (*s.begin() == 'C')
            {
                scores[1] += choice - 4;
                continue;
            }

            scores[1] += 4 - choice;
            continue;
        }

        if (any_of(s.begin(), s.end(), [](char ch) { return ch == 'J'; }))
        {
            if (*s.begin() == 'J')
            {
                scores[2] += choice - 4;
                continue;
            }

            scores[2] += 4 - choice;
            continue;
        }

        if (any_of(s.begin(), s.end(), [](char ch) { return ch == 'A'; }))
        {
            if (*s.begin() == 'A')
            {
                scores[3] += choice - 4;
                continue;
            }

            scores[3] += 4 - choice;
            continue;
        }
    }

    for (int i = 0; i < scores.size(); i++)
    {
        answer.push_back(scores[i] > 0? p[i][1] : p[i][0]);
    }

    
    return answer;
}