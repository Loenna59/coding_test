#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int brown_half = brown / 2;
    
    for (int i = 1; i <= brown_half - 2; i++)
    {
        int x = i;
        int y = brown_half - i - 2;

        if (x * y == yellow)
        {
            if (x > y)
            {
                answer.push_back(x + 2);
                answer.push_back(y + 2);
            }
            else
            {
                answer.push_back(y + 2);
                answer.push_back(x + 2);
            }
            break;
        }
    }
    
    return answer;
}