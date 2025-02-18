#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    // 1. 산술평균 : n개의 수들의 합을 n으로 나눈 값 (소수점 이하 첫째 자리에서 반올림한 값을 출력)
    // 2. 중앙값 : n개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
    // 3. 최빈값 : n개의 수들 중 가장 많이 나타나는 값 (여러개 있을 경우 최빈값 중 두 번째로 작은 값 출력)
    // 4. 범위 : 최대값과 최소값의 차이

    vector<int> answers;
    
    sort(nums.begin(), nums.end());
    
    int diff = nums.back() - nums.front();
    int medi = nums[n / 2];
    int sum = nums[0];
    int mode = nums[0];

    if (n > 1)
    {
        unordered_map<int, int> map;
        map.insert(make_pair(nums[0], 1));

        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            sum += num;

            if (map.find(num) == map.end())
            {
                map.insert(make_pair(num, 1));
                continue;
            }

            map[num]++;
        }

        vector<pair<int, int>> pairs(map.begin(), map.end());

        auto cmp = [] (pair<int, int> a, pair<int, int> b)
        {
            if (a.second == b.second)
            {
                return a.first < b.first;
            }

            return a.second > b.second;
        };

        sort(pairs.begin(), pairs.end(), cmp);

        auto itr = pairs.begin();

        mode = (*itr).second == (*(itr + 1)).second? (*(itr + 1)).first : (*itr).first;
    }

    cout << round(sum / (float)n) + 0 << "\n" << medi << "\n" << mode << "\n" << diff;
    
    return 0;
}