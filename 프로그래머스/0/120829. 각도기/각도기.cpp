#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int remain = angle % 90 > 0? 1 : 0;
    int answer = angle / 90 * 2 + remain;
    return answer;
}