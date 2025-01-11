#include <iostream>

int main()
{
    int* nums = new int[9];

    int max = 0;
    int max_index = 0;

    for (int i = 0; i < 9; i++)
    {
        std::cin >> nums[i];

        if (nums[i] > max)
        {
            max = nums[i];
            max_index = i + 1;
        }
    }

    std::cout << max << "\n" << max_index;

    delete nums;

    return 0;
}