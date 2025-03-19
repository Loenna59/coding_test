#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

int main()
{    
    int n;

    std::cin >> n;
    
    std::vector<int> nums(n);

    std::generate(nums.begin(), nums.end(), [inc = 1]() mutable { return inc++; });

    std::vector<int> nums3(n);

    std::generate(nums3.begin(), nums3.end(), [inc = 1]() mutable { return inc * inc * inc++; });

    int value1 = std::reduce(nums.begin(), nums.end(), 0);
    long value2 = value1 * value1;
    long value3 = std::reduce(nums3.begin(), nums3.end(), 0);

    std::cout << value1 << "\n" << value2 << "\n" << value3;

    return 0;
}