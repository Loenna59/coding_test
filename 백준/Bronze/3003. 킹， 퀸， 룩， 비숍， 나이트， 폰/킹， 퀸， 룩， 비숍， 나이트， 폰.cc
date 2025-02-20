#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int chess[6] { 1, 1, 2, 2, 2, 8 };

    for (int i = 0; i < 6; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }

        int input;
        cin >> input;
        cout << chess[i] - input;
    }
    
    return 0;
}