#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;

    cin >> num;

    vector<int> scores;

    for (int i = 0; i < num; i++)
    {
        int input;
        cin >> input;
        scores.push_back(input);
    }

    sort(scores.rbegin(), scores.rend());

    float total_score = 0;

    for (int i = 0; i < scores.size(); i++)
    {
        float r = (scores[i] / (float)scores[0] * 100);
        total_score += r;
    }

    float result = total_score / (float)scores.size();

    cout << fixed << showpoint;

    if (result == int(result))
    {
        cout.precision(1);
    }

    cout << result;

    return 0;
}