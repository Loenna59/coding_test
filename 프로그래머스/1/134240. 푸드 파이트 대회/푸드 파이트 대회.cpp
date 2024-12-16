#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    for (int i = 1; i < food.size(); i++) {
        int count = food[i] / 2;
        
        if (count <= 0)
        {
            continue;
        }
        
        answer.append(count, i + 48);
    }
    
    answer.push_back('0');
    
    for (int i = food.size() - 1; i >= 1; i--) {
        int count = food[i] / 2;
        
        if (count <= 0)
        {
            continue;
        }
        
        answer.append(count, i + 48);
    }
    
    return answer;
}