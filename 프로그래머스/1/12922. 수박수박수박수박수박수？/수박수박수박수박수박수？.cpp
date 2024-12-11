#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    vector<string> pattern = vector<string>( {"수", "박"} );
    
    for (int i = 0; i < n; i++)
    {
        answer.append(pattern[i & 1]);
    }
    
    return answer;
}