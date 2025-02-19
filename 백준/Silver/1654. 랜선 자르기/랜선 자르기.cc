#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int k;

    cin >> k >> n;

    vector<long long> cables;

    long long min = 1;
    long long max;

    for (int i = 0; i < k; i++)
    {
        long long input;
        cin >> input;
        cables.push_back(input);

        if (max < input)
        {
            max = input;
        }
    }

    long long result;

    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long count = 0;

        for (int i = 0; i < k; i++)
        {
            count += cables[i] / mid;

            if (count >= n)
            {
                break;
            }
        }

        if (count >= n) // 길이를 더 늘릴 수 있음
        {
            result = mid;
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    
    cout << result;
    
    return 0;
}