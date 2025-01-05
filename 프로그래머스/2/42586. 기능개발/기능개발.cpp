#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int completed_order = 0;

    while (completed_order < progresses.size())
    {
        for (int i = completed_order; i < progresses.size(); i++)
        {
            if (progresses[i] < 100)
            {
                progresses[i] += speeds[i];
            }
        }

        if (progresses[completed_order] >= 100)
        {
            int count = 0;
            
            for (int i = completed_order; i < progresses.size(); i++)
            {
                if (progresses[i] < 100)
                {
                    break;
                }
                count++;
            }

            completed_order += count;
            answer.push_back(count);
        }
    }
    
    return answer;
}