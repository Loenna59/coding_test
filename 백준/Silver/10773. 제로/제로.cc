#include <iostream>
#include <stack>

int main()
{
    int n;
    std::cin >> n;

    std::stack<int> s;

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        int input;

        std::cin >> input;

        if (input == 0 && !s.empty())
        {
            int v = s.top();
            sum -= v;
            s.pop();

            continue;
        }

        sum += input;
        s.push(input);
    }

    std::cout << sum;

    return 0;
}