#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    double s = sqrt(n);
    double r = remainder(s, 1); 
    
    answer = (r == 0)? pow(s + 1, 2) : -1;
    
    return answer;
}