#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

bool all_demical(char ch) {
    int demical = ch ^ 48;
    return demical >= 0 && demical < 10;
}

bool solution(string s) {
    bool answer = true;
    
    int len = s.size();

    answer = all_of(s.begin(), s.end(), all_demical);

    return answer && (len == 4 || len == 6);
}