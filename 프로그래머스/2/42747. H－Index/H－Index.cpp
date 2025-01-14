#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 논문의 인용 횟수 배열이 [3, 0, 6, 1, 5]일 때:

// 각 논문의 인용 횟수를 내림차순 정렬: [6, 5, 3, 1, 0]
// i+1과 인용 횟수를 비교:
//     1번째 논문(6번 인용): 6 >= 1 (조건 충족)
//     2번째 논문(5번 인용): 5 >= 2 (조건 충족)
//     3번째 논문(3번 인용): 3 >= 3 (조건 충족)
//     4번째 논문(1번 인용): 1 >= 4 (조건 불충족)
// 조건이 처음으로 충족되지 않는 순간의 이전 값인 3이 H-Index입니다.

int solution(vector<int> citations) {
    
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); i++)
    {
        if (citations[i] < (i + 1))
        {
            return i;
        }
    }

    return citations.size();
}