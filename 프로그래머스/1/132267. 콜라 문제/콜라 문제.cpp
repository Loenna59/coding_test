#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a)
    {
        int x = n / a;

        n -= a * x;
        n += b * x;

        answer += b * x;
    }
    
    return answer;
}