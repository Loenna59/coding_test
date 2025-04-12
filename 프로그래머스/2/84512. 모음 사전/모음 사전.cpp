#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int solution(string word) 
{
    int answer = 0;

    unordered_map<char, int> alphabet 
    {
        { 'A', 0 },
        { 'E', 1 }, 
        { 'I', 2 },
        { 'O', 3 },
        { 'U', 4 }
    };

    int weight[5] { 781, 156, 31, 6, 1 }; // 5^n + 5^{n-1} +... + 1

    for (int i = 0, count = word.size(); i < count; i++)
    {
        answer += alphabet[word[i]] * weight[i] + 1;
    }

    return answer;
}