#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    n -= 1;
    int answer = 1;

    while (true)
    {
        n -= 6 * answer;
        answer++;

        if (n <= 0)
        {
            break;
        }
    }

    cout << answer;

    return 0;
}