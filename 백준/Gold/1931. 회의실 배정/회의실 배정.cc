#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;

    std::vector<std::pair<long, long>> schedule(n);

    for (int i = 0; i < n; i++)
    {
        long start;
        long end;

        std::cin >> start >> end;

        schedule[i] = std::make_pair(start, end);
    }


    // 제일 일찍 끝나는 순으로 -> 같으면 제일 일찍 시작하는 순
    auto comp = [](std::pair<long, long>& a, std::pair<long, long>& b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }

        return a.second < b.second;
    };

    std::sort(schedule.begin(), schedule.end(), comp);

    std::vector<std::pair<long, long>> result;
    result.push_back(schedule[0]);

    for (int i = 1, count = schedule.size(); i < count; i++)
    {
        long back_end = result.back().second;
        long next_first = schedule[i].first;

        // 끝나는 시간과 다음 시작 시간 비교 (시작 시간이 무조건 같거나 커야함!)
        if (back_end <= next_first)
        {
            result.push_back(schedule[i]);
        }
    }

    std::cout << result.size();

    return 0;
}