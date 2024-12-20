#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string solution(string X, string Y) {
    string answer;

    int XNum[10] = {0,};
    int YNum[10] = {0,};
    int AnswerNum[10] = {0,};

    for (int i = 0; i < X.size(); ++i)
    {
        int key = X[i] - '0';
        XNum[key]++;
    }

    for (int i = 0; i < Y.size(); ++i)
    {
        int key = Y[i] - '0';
        YNum[key]++;        
    }

    for (int i = 0; i < 10; ++i)
    {
       AnswerNum[i] = min(XNum[i], YNum[i]);
    }

    for (int i = 9; i >= 1; --i)
    {
        while (AnswerNum[i]--)
        {
            answer += to_string(i);
        }
    }

    if (AnswerNum[0] > 0)
    {
        if (answer.size() == 0)
        {
            answer = "0";
        }
        else
        {
            while (AnswerNum[0]--)
            {
                answer += to_string(0);
            }
        }
    }


    if (answer.size() == 0)
    {
        answer = "-1";
    }

    return answer;
}