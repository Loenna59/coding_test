#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> numbers;
    std::vector<int> totals(30);

    std::generate(totals.begin(), totals.end(), [n = 1]() mutable { return n++; });

    for (int i = 0; i < 28; i++)
    {
        int input;
        std::cin >> input;
        numbers.push_back(input);
    }

    std::sort(numbers.begin(), numbers.end());

    std::vector<int> results(2);

    std::set_difference(totals.begin(), totals.end(), numbers.begin(), numbers.end(), results.begin());

    std::cout << *results.begin() << "\n" << *(results.begin() + 1);

    return 0;
}