#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    vector<int> hof;
    
    for (int i = 0; i < score.size(); i++)
    {
        hof.push_back(score[i]);
        sort(hof.begin(), hof.end());
        
        if (i >= k)
        {
            hof.erase(hof.begin());
        }

        answer.push_back(*(hof.begin()));
    }
    
    return answer;
}