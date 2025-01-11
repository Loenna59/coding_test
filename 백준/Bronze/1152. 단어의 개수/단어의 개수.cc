#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string sentence;
    getline(std::cin, sentence);

    char whitespace = ' ';

    std::istringstream ss(sentence);
    std::string tmp;
    int count = 0;

    while (getline(ss, tmp, whitespace))
    {
        if (!tmp.empty())
        {
            count++;
        }
    }

    std::cout << count;

    return 0;
}