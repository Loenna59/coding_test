#include <string>
#include <vector>
#include <map>

using namespace std;

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

    for(pair<string, int> p : categories)
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