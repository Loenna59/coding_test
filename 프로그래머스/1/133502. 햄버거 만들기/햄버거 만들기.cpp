#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    string burger("1231");
    string stack;

    for (int item : ingredient)
    {
        stack.push_back(item + 48);

        if (stack.size() < 4)
        {
            continue;
        }

        if (stack.substr(stack.size() - 4, 4) == burger)
        {
            answer++;
            for (int i = 0; i < 4; i++)
            {
                stack.pop_back();
            }
        }
    }
    
    return answer;
}