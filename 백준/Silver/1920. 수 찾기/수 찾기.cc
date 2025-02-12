#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int m;

    unordered_map<int, int> map;
    vector<int> answers;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        map.insert({num, 1});
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        answers.push_back(map.find(num) == map.end()? 0 : 1);
    }

    for (int i = 0, count = answers.size(); i < count; i++)
    {
        if (i > 0)
        {
            cout << "\n";
        }

        cout << answers[i];
    }

    return 0;
}