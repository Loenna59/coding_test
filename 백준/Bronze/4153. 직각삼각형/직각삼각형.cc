#include <iostream>
#include <string>

int main()
{
    std::string result;

    while (true)
    {
        int nums[3];

        std::cin >> nums[0] >> nums[1] >> nums[2];

        if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0)
        {
            break;
        }

        long long largest_index = 0;

        for (int i = 1; i < 3; i++)
        {
            if (nums[i] > nums[largest_index])
            {
                largest_index = i;
            }
        }

        long long r = nums[largest_index] * nums[largest_index];
        long long l = (nums[0] * nums[0]) + (nums[1] * nums [1]) + (nums[2] * nums[2]) - r;

        if (!result.empty())
        {
            result.append("\n");
        }
        result.append((r == l? "right" : "wrong"));
    }

    std::cout << result;

    return 0;
}