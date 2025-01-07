#include <iostream>
#include <string>

int main() 
{
    int N;
    std::cin >> N;

    std::string input;
    std::cin >> input;

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        if (i >= input.size())
        {
            break;
        }

        result += input[i] ^ 48;
    }

    std::cout << result;

    return 0;
}