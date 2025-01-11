#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    float score = 0.0f;
    
    const char* grade = str.c_str();
    std::cout << std::fixed;
    std::cout.precision(1);

    if ((int)grade[0] < 'E')
    {
        score = 69 - (float)grade[0];

        if (str.size() > 1 && grade[1] != '0')
        {
            score -= ((float)grade[1] - 44) * 0.3f;
        }

    }

    std::cout << score;

    return 0;
}