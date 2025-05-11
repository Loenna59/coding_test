#include <iostream>
#include <string>
#include <vector>

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> answers;
    
    while (true)
    {
        std::string n;

        std::cin >> n;

        if (n == "0")
        {
            break;
        }

        int decimal = 0;

        for (int i = 0, count = n.size(); i < count; i++)
        {
            int ch = n[i] - '0';

            decimal += (ch * factorial(count - i)); 
        }

        answers.push_back(decimal);
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