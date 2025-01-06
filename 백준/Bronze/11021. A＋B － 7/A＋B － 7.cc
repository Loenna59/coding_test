#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int T;

    cin >> T;

    vector<string> cases;

    for (int i = 0; i < T; i++)
    {
        string c;
        getline(cin >> ws, c);
        cases.push_back(c);
    }

    for (int i = 0; i < cases.size(); i++)
    {
        int A = stoi(cases[i].substr(0, 1));
        int B = stoi(cases[i].substr(2));

        cout << "Case #" << i+ 1 << ": " << A + B << "\n";
    }

    return 0;
}