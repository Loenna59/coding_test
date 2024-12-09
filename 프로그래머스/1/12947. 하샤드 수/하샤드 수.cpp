#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    string str = to_string(x);

    int n = 0;

    for (int i = 0; i < str.size(); i++)
    {
        n += str[i] ^ 48;
    }

    answer = x % n == 0;
    
    return answer;
}