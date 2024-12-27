#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int min;
    int max;

    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;

        if (i == 0)
        {
            min = elem;
            max = elem;
            continue;
        }

        if (elem < min)
        {
            min = elem;
        }

        if (elem > max)
        {
            max = elem;
        }
    }

    cout << min << " " << max;

    return 0;
}