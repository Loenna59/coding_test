#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    std::string* markings = new std::string[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> markings[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }
        
        int point = 0;
        int scores = 0;
        std::string marking = markings[i];
        for (std::string::iterator it = marking.begin(); it != marking.end(); it++)
        {
            if (*it == 'O')
            {
                scores += ++point;
            }
            else
            {
                point = 0;
            }
        }

        std::cout << scores;
    }

    return 0;
}