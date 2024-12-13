#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    long long p_num = stoll(p);
    int len = t.size() - p.size() + 1;

    for (int i = 0; i < len; i++)
    {
        string subset = t.substr(i, p.size());
        long long num = stoll(subset);

        if (num <= p_num)
        {
            answer++;
        }
    }
    
    return answer;
}