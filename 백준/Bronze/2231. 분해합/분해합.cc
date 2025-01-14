#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int result = 0; // 생성자를 저장할 변수

    for (int i = 1; i < n; i++)
    {
        int sum = i;
        int temp = i;

        // 각 자릿수의 합을 계산
        while (temp > 0) {
            sum += temp % 10; // 마지막 자릿수 더하기
            temp /= 10;       // 마지막 자릿수 제거
        }

        // 분해합이 n과 같으면 결과 저장
        if (sum == n) {
            result = i;
            break; // 가장 작은 생성자를 찾았으므로 종료
        }
    }

    cout << result; // 생성자가 없으면 기본값 0 출력

    return 0;
}