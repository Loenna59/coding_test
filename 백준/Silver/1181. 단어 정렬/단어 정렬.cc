#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    cin >> n;

    auto cmp = [](string a, string b) {
        if (a.size() == b.size())
        {
            return a < b;
        }

        return a.size() < b.size();
    };

    set<string, decltype(cmp)> words(cmp);

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.insert(word);
    }

    for (set<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        if (it != words.begin())
        {
            cout << "\n";
        }

        cout << *it;
    }
    return 0;
}