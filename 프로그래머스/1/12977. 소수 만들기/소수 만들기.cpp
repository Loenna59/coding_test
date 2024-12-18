#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    int size = nums.size();
    int sum = 0;
    for (int i = 0; i < size - 2; ++i)
    {
        for (int j = i + 1; j < size - 1; ++j)
        {
            for (int k = j + 1; k < size; ++k)
            {
                sum = nums[i] + nums[j] + nums[k];

                bool isA = true;

                for (int l = 2; l <= sqrt(sum); ++l)
                {
                    if (sum % l == 0)
                    {
                        isA = false;
                        break;
                    }
                }

                if (isA)
                {
                    answer++;
                }
            }
        }
    }

    return answer;
}