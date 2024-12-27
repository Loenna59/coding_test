#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers;

    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        numbers.push_back(elem);
    }

    cout << *min_element(numbers.begin(), numbers.end()) << " " << *max_element(numbers.begin(), numbers.end());

    return 0;
}