#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    
    cin >> n;

    // 가장 큰 봉지에 최대로 담을 수 있는 개수를 알아낸다
    // 가장 큰 봉지 개수를 덜어내면서 개수를 알아낸다 -> 최소 개수 갱신
    int count = n / 5;
    int current_weight = n % 5;
    
    int minCount = n / 3;

    bool right = n % 3 == 0 || n % 5 == 0;

    for (int i = 0; i <= count; i++)
    {
        int remain_weight = current_weight + 5 * i;

        int addCount = remain_weight / 3;

        if (remain_weight % 3 == 0)
        {
            minCount = min(minCount, count - i + addCount);
            right = true;
        }
    }

    if (!right)
    {
        minCount = -1;
    }

    cout << minCount;

    return 0;
}