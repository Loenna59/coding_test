#include <iostream>
#include <string>
#include <cstdio>

int main()
{
    int a;
    int b;
    int c;

    std::cin >> a >> b >> c;

    long long mul = a * b * c;

    char buf[100]{ '\0' };
    int answer[10]{ 0 };

    sprintf(buf, "%ld", mul);

    for (int i = 0; i < 100; i++)
    {
        if (buf[i] != '\0')
        {
            int index = buf[i] - 48;
            answer[index]++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }
        std::cout << answer[i];
    }

    return 0;
}