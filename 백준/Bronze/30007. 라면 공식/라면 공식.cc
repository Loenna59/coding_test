#include <iostream>
#include <vector>

int main()
{    
    int n;

    std::cin >> n;

    std::vector<int> answers(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        int b;
        int x;

        std::cin >> a >> b >> x;

        answers[i] = a * (x - 1) + b;
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }

        std::cout << answers[i];
    }

    return 0;
}