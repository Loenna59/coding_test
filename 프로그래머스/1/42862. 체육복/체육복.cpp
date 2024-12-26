#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> students;
    students.assign(n, 1);


    for (int i = 0; i < lost.size(); i++)
    {
        int elem = lost[i];
        students[elem - 1] -= 1;
    }

    for (int i = 0; i < reserve.size(); i++)
    {
        int elem = reserve[i];
        students[elem - 1] += 1;
    }

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i] >= 1)
        {
            answer++;
            continue;
        }

        if (i > 0 && students[i - 1] > 1)
        {
            students[i - 1]--;
            answer++;
            continue;
        }

        if (i < students.size() - 1 && students[i + 1] > 1)
        {
            students[i + 1]--;
            answer++;
            continue;
        }
    }
    
    return answer;
}