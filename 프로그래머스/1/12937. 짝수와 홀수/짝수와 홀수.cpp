#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    // string answer = num % 2 == 0? "Even" : "Odd";
    
    // 비트 연산으로 하는 방법이 더 좋다
    string answer = num & 1? "Odd" : "Even";
    return answer;
}