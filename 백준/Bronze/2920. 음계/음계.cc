#include <iostream>
#include <string>

int main()
{
    int nums[8];

    for (int i = 0; i < 8; i++)
    {
        std::cin >> nums[i];
    }

    if (nums[0] != 1 && nums[0] != 8)
    {
        std::cout << "mixed";

        return 0;
    }

    bool asc = nums[0] == 1;

    for (int i = 1; i < 8; i++)
    {
        int sub = 0;
        if (asc)
        {
            sub = nums[i] - nums[i - 1];
        }
        else
        {
            sub = nums[i- 1] - nums[i];
        }

        if (sub > 1)
        {
            std::cout << "mixed";

            return 0;
        }
    }

    std::cout << (asc? "ascending" : "descending");

    return 0;
}