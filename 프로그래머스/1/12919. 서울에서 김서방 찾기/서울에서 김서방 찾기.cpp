#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";

    vector<string>::iterator inter = find(seoul.begin(), seoul.end(), "Kim");

    answer.append(to_string(inter - seoul.begin()));
    answer.append("에 있다");
    
    return answer;
}