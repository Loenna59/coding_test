#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    cin >> n;
    cin.ignore();

    vector<pair<int, int>> people;

    for (int i = 0; i < n; i++)
    {
        string input;
        getline(cin, input);

        int split_index = input.find(' ');

        int weight = stoi(input.substr(0, split_index));
        int height = stoi(input.substr(split_index + 1));

        people.push_back({weight, height});
    }

    vector<int> answers;

    // 자기보다 덩치가 큰 사람이 몇 명인지 => 자신의 랭크
    for (int i = 0, count = people.size(); i < count; i++)
    {
        pair<int, int> current = people[i];
        int rank = 1;

        for (int j = 0, count = people.size(); j < count; j++)
        {
            if (i == j)
            {
                continue;
            }

            pair<int, int> other = people[j];

            if (other.first > current.first && other.second > current.second)
            {
                rank++;
            }
        }

        answers.push_back(rank);
    }

    for (int i = 0, count = answers.size(); i < count; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }

        cout << answers[i];
    }

    return 0;
}