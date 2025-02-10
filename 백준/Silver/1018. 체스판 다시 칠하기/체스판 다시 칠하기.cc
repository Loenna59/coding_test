#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int get_count(const vector<string>& board, int start_index, int x, int y)
{
    const char color[2] = {'W', 'B'};
    int count = 0;
    int col_index;

    for (int i = 0; i < 8; i++)
    {
        col_index = (start_index + i) % 2;

        for (int j = 0; j < 8; j++)
        {
            if (board[x + i][y + j] != color[col_index])
            {
                count++;
            }

            col_index = (col_index + 1) % 2;
        }
    }

    return count;
}

int main()
{
    int n;
    int m;

    cin >> n >> m;

    vector<string> board;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        board.push_back(input);
    }

    int min_count = 64;

    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int count_1 = get_count(board, 0, i, j);
            int count_2 = get_count(board, 1, i, j);

            min_count = min(min_count, min(count_1, count_2));
        }
    }

    cout << min_count;

    return 0;
}