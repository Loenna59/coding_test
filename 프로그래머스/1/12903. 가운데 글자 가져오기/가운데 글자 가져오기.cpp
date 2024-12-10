#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int size = s.size();

    int begin = (size - 1) >> 1;
    int len = 2 >> (size & 1);
    
    answer = s.substr(begin, len);
    
    return answer;
}