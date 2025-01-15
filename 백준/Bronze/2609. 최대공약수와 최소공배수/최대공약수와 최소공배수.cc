#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a;
    int b;

    cin >> a >> b;

    int min_num = min(a, b);
    int gcd = 1;
    for (int i = 1; i <= min_num; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }

    cout << gcd << "\n";

    int lcm = gcd * ( a / gcd) * (b / gcd);

    cout << lcm;

    return 0;
}