#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    for (vector<string>::iterator it = goal.begin(); it != goal.end(); it++)
    {
        if((*it).compare(*cards1.begin()) == 0)
        {
            cards1.erase(cards1.begin());
        }
        else
        if((*it).compare(*cards2.begin()) == 0)
        {
            cards2.erase(cards2.begin());
        }
        else
        {
            return "No";
        }
    }
    
    return "Yes";
}