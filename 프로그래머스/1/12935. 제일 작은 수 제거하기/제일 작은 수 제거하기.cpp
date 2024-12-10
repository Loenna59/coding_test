#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    
    int min_val = *min_element(answer.begin(), answer.end());

    auto pos = find(answer.begin(), answer.end(), min_val) - answer.begin();
    
    answer.erase(answer.begin() + pos);

    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}