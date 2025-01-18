#include <iostream>

int main()
{
    long long a;
    long long b;
    long long v;

    std::cin >> a >> b >> v;

    long long answer = 1;

    if (a >= v)
    {
        std::cout << answer;
        return 0;
    }

    answer += (v - a) / (a - b);

    if ((v - a) % (a - b) > 0)
    {
        answer++;
    }

    std::cout << answer;

    return 0;
}