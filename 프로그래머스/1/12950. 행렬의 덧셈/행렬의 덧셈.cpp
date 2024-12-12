#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
     vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> t(arr1[i].size());

        transform(arr1[i].begin(), arr1[i].end(), arr2[i].begin(), t.begin(), [](int a, int b) { return a + b; });

        answer.push_back(t);
    }
    
    return answer;
}