#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    string input[3];

    for (int i = 0; i < 3; i++)
    {
        std::cin >> input[i];
    }

    int next_num = 0;

    for (int i = 0; i < 3; i++)
    {
        if (input[i][0] != 'F' && input[i][0] != 'B')
        {
            next_num = stoi(input[i]) + 1;
            continue;
        }
        else if (next_num > 0)
        {
            next_num += 1;
        }
    }

    if (next_num % 15 == 0)
    {
        std::cout << "FizzBuzz";
    }
    else if (next_num % 3 == 0)
    {
        std::cout << "Fizz";
    }
    else if (next_num % 5 == 0)
    {
        std::cout << "Buzz";
    }
    else
    {
        std::cout << next_num;
    }

    return 0;
}