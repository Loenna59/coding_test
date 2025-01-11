#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    int alphabets[26];

    std::fill(alphabets, alphabets + 26, -1);

    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 97;

        if (alphabets[index] < 0)
        {
            alphabets[index] = i;
        }
    }

    int size = sizeof(alphabets) / sizeof(*alphabets);

    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            std::cout << " ";
        }
        std::cout << alphabets[i];
    }

    return 0;
}