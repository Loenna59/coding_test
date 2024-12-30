#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {

        string number_1 = phone_book[i];
        string number_2 = phone_book[i + 1];

        if (number_1 == number_2.substr(0, number_1.size()))
        {
            answer = false;
            break;
        }
    }

    return answer;
}