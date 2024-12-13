#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    int size = number.size();

    for (int i = 0; i < (1 << size); i++)
    {
        vector<int> subset;
        for (int j = 0; j < size; j++)
        {
            if (i & ( 1 << j))
            {
                subset.push_back(number[j]);
            }
        }

        if (subset.size() == 3)
        {
            int sum = 0;
            for (int i = 0; i < subset.size(); i++)
            {
                sum += subset[i];
            }
            
            if (sum == 0)
            {
                answer++;
            }
        }

    }
    
    return answer;
}