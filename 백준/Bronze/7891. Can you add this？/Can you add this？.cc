#include <iostream>
#include <vector>

int main()
{    
    int t;

    std::cin >> t;

    std::vector<int> answers(t);

    for (int i = 0; i < t; i++)
    {
        long long x;
        long long y;
        
        std::cin >> x >> y;

        answers[i] = x + y;
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