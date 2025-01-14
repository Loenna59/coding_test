#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    auto cmp = [] (string a, string b) 
    {
        return (a + b) < (b + a);
    };

    priority_queue<string, vector<string>, decltype(cmp)> heap(cmp);
    
    for (int number : numbers)
    {
        heap.push(to_string(number));
    }

    while (!heap.empty())
    {
        string pop = heap.top();
        heap.pop();
        answer.append(pop);
    }
    
    if (answer[0] == '0') 
    {
        return "0";
    }
    
    return answer;
}