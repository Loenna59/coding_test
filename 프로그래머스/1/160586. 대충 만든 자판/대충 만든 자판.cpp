#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for (string target : targets)
    {
        int result = 0;
        for (int i = 0; i < target.size(); i++)
        {
            char ch = target[i];

            int min = 100;

            for (string key : keymap)
            {
                size_t first_of = key.find_first_of(ch);
                if (first_of != string::npos && first_of + 1 < min)
                {
                    min = first_of + 1;
                }
            }

            if (min == 100)
            {
                result = -1;
                break;
            }

            result += min;
        }

        answer.push_back(result);
    }
    
    return answer;
}