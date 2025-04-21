#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long a;
    long long b;

    std::vector<std::string> answers;

    while (true)
    {
        std::cin >> a >> b;

        if (a == 0 && b == 0)
        {
            break;
        }

        std::string answer = a > b? "Yes" : "No";

        answers.push_back(answer);
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