#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
     int answer = 1;

    int ritr = *section.rbegin() - m;

    while(!section.empty())
    {
        if (ritr < *section.rbegin())
        {
            section.pop_back();
            continue;
        }

        answer++;
        ritr = *section.rbegin() - m;
    }

    return answer;
}