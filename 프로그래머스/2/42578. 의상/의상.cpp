#include <string>
#include <vector>
#include <map>

using namespace std;

// 각 종류의 의상을 1개를 입거나 안 입을 경우의 수를 계산하고 모두 곱한다.
// 최소 1가지의 의상을 입어야하므로 아무거도 안 입는 1가지는 제외해야한다.

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> categories;

    for (int i = 0; i < clothes.size(); i++)
    {
        if (categories.find(clothes[i][1]) == categories.end())
        {
            categories.insert({clothes[i][1], 1});
            continue;
        }

        categories[clothes[i][1]]++;
    }

    for (pair<string, int> p : categories)
    {
        if (answer == 0)
        {
            answer = p.second + 1;
            continue;
        }

        answer *= (p.second + 1);
    }
    
    return answer - 1;
}