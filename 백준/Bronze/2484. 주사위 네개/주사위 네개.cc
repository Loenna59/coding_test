#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main()
{
    int n;

    std::cin >> n;

    int max_score = 0;

    for (int i = 0; i < n; i++)
    {
        std::unordered_map<int, int> map;
        
        for (int x = 0; x < 4; x++)
        {
            int input;

            std::cin >> input;

            map[input]++;
        }
        
        std::vector<std::pair<int, int>> v(map.begin(), map.end());

        auto comp = [](std::pair<int, int>& a, std::pair<int, int>& b) 
        {
            if (a.second == b.second)
            {
                return a.first > b.first;
            }
            return a.second > b.second; 
        };

        std::sort(v.begin(), v.end(), comp);

        int count = v.front().second;
        int number = v.front().first;

        int score;

        switch (count)
        {
        case 4:
            score = 50000 + number * 5000;
            break;
        case 3:
            score = 10000 + number * 1000;
            break;
        case 2:
            if (v[1].second == 2)
            {
                score = 2000 + (number + v[1].first) * 500;
            }
            else
            {
                score = 1000 + number * 100;
            }
            break;
        default:
            score = number * 100;
            break;
        }

        if (max_score < score)
        {
            max_score = score;
        }
    }

    std::cout << max_score;

    return 0;
}