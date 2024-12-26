#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            if (j > i && j < (n * 2) - i)
            {
                cout << "*";
                continue;
            }
            
            if (j < i)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            if (j > n - i - 1 && j < n + i + 1)
            {
                cout << "*";
                continue;
            }

            if (j < n - i - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}