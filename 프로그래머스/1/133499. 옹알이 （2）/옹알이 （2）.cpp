#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    const vector<string> nephew_babbling({ "aya", "ye", "woo", "ma"});

    for (string element : babbling)
    {
        for (string str : nephew_babbling)
        {
            int position = element.find(str);
            if (position != string::npos)
            {
                element.erase(element.begin() + position, element.begin() + position + str.size());
            }

            if (element.empty())
            {
                answer++;
                break;
            }
        }
    }

    return answer;
}