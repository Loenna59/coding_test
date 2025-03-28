#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++) {
        vector<int> command = commands[i];

        vector<int> sub_arr = vector<int>(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(sub_arr.begin(), sub_arr.end());

        answer.push_back(sub_arr[command[2] - 1]);
    }
    
    return answer;
}