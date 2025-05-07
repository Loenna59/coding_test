#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<char, int> map
    {
        {'-', 0},
        {'\\', 1},
        {'(', 2},
        {'@', 3},
        {'?', 4},
        {'>', 5},
        {'&', 6},
        {'%', 7},
        {'/', -1}
    };

    std::vector<long> answers;

    while (true)
    {
        std::string str;

        std::cin >> str;

        if (str == "#")
        {
            break;
        }

        long result = 0;

        for (int i = 0, size = str.size(); i < size; i++)
        {
            char ch = str[i];
            long num = map[ch] * pow(8, (size - 1 - i));
            result += num;
        }

        answers.push_back(result);
    }
    
    for (int i = 0, count = answers.size(); i < count; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }
        std::cout << answers[i];
    }

    return 0;
}
