#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    int size = phone_number.size();

    for (int i = 0; i < size; i++)
    {
        if (size - i > 4)
        {
            answer.push_back('*');
            continue;
        }

        answer.push_back(phone_number[i]);
    }
    
    // 다른 사람 풀이 (replace)
    // answer = phone_number;
//     int size = phone_number.size();

//     for (int i = 0; i < size - 4; i++)
//     {
//        answer.replace(i, 1, "*");
//     }
    
    return answer;
}