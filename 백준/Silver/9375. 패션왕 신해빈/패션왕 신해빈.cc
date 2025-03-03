#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;

    std::cin >> t;

    std::vector<int> answers(t);

    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;

        std::unordered_map<std::string, int> map; 

        for (int i = 0; i < n; i++)
        {
            std::string key;
            std::string value;

            std::cin >> value >> key;

            map[key]++;
        }

        answers[i] = 1;

        for (std::pair<std::string, int> p : map)
        {
            answers[i] *= (p.second + 1);
        }
        
        answers[i]--;
    }

    for (int i = 0; i < t; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }

        std::cout << answers[i];
    }

    return 0;
}