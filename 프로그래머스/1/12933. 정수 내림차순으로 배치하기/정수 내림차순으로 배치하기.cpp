#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    string str = to_string(n);

// 내가 작성한 것
//     vector<int> vec;

//     for (int i = 0; i < str.size(); i++)
//     {
//         vec.push_back(str[i] ^ 48);
//     }

//     sort(vec.begin(), vec.end());

//     for (int i = 0; i < vec.size(); i++)
//     {
//         long long val = vec[i] * pow(10, i);
//         answer += val;
//     }

// string으로 sort하면 되네;;
    sort(str.rbegin(), str.rend());

    answer = stoll(str);
    
    return answer;
}