#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (int n = left; n <= right; n++)
    {
        int count = 0;

        for (int i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0) // 딱 나누어 떨어진다면
            {
                count++;

                if (i != n / i) // 이미 구해진 약수로 나눈다 -> 추가 약수를 알 수 있음
                {
                    count++;
                }
            }
        }

        answer += (count & 1)? -n : n;
    }

    return answer;
}