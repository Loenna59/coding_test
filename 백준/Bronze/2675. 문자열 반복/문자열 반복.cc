#include <iostream>
#include <string>

int main()
{
    int t;

    std::cin >> t;

    std::string* strs = new std::string[t];
    std::cin.ignore();

    for (int i = 0; i < t; i++)
    {
        getline(std::cin, strs[i]); 
    }

    for (int i = 0; i < t; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }

        std::string p;
        int r = std::stoi(strs[i].substr(0, 1));

        for (char c : strs[i].substr(2))
        {
            std::string s;
            s.resize(r);
            std::fill(s.begin(), s.begin() + r, c); 
            p.append(s);
        }

        std::cout << p;
    }

    return 0;
}