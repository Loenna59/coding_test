#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> s_1({1, 2, 3, 4, 5});
    vector<int> s_2({2, 1, 2, 3, 2, 4, 2, 5});
    vector<int> s_3({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});

    vector<int> arr({0, 0, 0});

    for (int i = 0; i < answers.size(); i++)
    {
        int a = answers[i];
        if (s_1[i % s_1.size()] == a)
        {
            arr[0]++;
        }

        if (s_2[i % s_2.size()] == a)
        {
            arr[1]++;
        }

        if (s_3[i % s_3.size()] == a)
        {
            arr[2]++;
        }
    }

    int m = *max_element(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= m)
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}