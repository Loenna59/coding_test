#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int total_size = n * 2 - 1;

    for (int i = 1; i <= n; i++)
    {
        int count = i * 2 - 1;
        int blank_count = n - i;

        for (int j = 1; j <= total_size; j++)
        {
            if (j <= blank_count)
            {
                cout << " ";
                continue;
            }

            if (j > total_size - blank_count)
            {
                continue;
            }

            if (i == n || j == blank_count + 1 || j == total_size - blank_count)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}