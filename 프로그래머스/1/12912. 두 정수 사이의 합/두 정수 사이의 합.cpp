#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = ((long long)(abs(a - b) + 1) * (a + b)) / 2;
    return answer;
}