#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);

    int n;

    std::cin >> n;

    std::vector<int> t(n);
    std::unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        std::cin >> t[i];
    }

    int left = 0;
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        map[t[i]]++;

        while (map.size() > 2)
        {
            if (map[t[left]] == 1)
            {
                map.erase(t[left]);
            }
            else
            {
                map[t[left]]--;
            }

            left++;
        }

        answer = std::max(answer, i - left + 1);
    }
    
    std::cout << answer;

    return 0;
}