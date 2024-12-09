#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = -1;

    long long result = (long long)num;
    
    for (int i = 0; i < 500; i++)
    {
        if (result == 1)
        {
            answer = i;
            break;
        }
        
        // result >> 1 == result / 2
        result = result & 1? result * 3 + 1 : result >> 1;
    }
    
    return answer;
}