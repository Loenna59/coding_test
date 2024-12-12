#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int num = n;
    vector<int> ternary;

    while (num > 0)
    {
        ternary.push_back(num % 3);
        num /= 3;
    }
    
    int size = ternary.size();
    
    for (int i = size - 1; i >= 0; i--)
    {
        if (ternary[i] > 0)
        {
            answer += pow(3, size - 1 - i) * ternary[i];
        }
    }
    
    return answer;
}