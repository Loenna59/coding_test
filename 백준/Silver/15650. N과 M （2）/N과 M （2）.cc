#include <iostream>
#include <vector>

void backtrack(int n, int m, int start, std::vector<int>& selected)
{
    if (selected.size() == m)
    {
        for (int num : selected)
        {
            std::cout << num << " ";
        }

        std::cout << "\n";
        return;
    }

    for (int i = start; i <= n; ++i)
    {
        selected.push_back(i);
        backtrack(n, m, i + 1, selected);
        selected.pop_back();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int m;

    std::cin >> n >> m;

    std::vector<int> selected;

    backtrack(n, m, 1, selected);

    return 0;
}