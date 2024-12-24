#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
        string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.rbegin(), completion.rend());

    for (string part : participant)
    {
        if (completion.empty() || completion.back() != part)
        {
            answer = part;
            break;
        }

        completion.pop_back();
    }

    return answer;
}