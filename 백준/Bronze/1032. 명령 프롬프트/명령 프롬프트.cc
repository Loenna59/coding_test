#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::string> files(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> files[i];
    }

    int length = files[0].size();
    std::string result;

    for (int i = 0; i < length; ++i)
    {
        char current = files[0][i];
        bool same = true;

        for (int j = 1; j < n; ++j)
        {
            if (files[j][i] != current)
            {
                same = false;
                break;
            }
        }

        result += same ? current : '?';
    }

    std::cout << result << '\n';
    return 0;
}