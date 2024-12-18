#include <vector>
#include <set>
#include <cmath>

using namespace std;

int solution(vector<int> nums)
{
    // 중복 제거 / 중복 제거한 배열 수가 n/2 마릿수보다 크거나 같으면 => 최대 종류 수 n/2
    // 중복 제거 / 중복 제거한 배열 수가 n/2 마릿수보다 작으면 => 중복 제거 수
    
    int choice_count = nums.size() / 2;
    
    set<int> num_set(nums.begin(), nums.end());
    
    int unique_num_size = num_set.size();
    
    return min(unique_num_size, choice_count);
}