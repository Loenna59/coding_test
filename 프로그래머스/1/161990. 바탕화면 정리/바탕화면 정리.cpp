#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer {-1, -1, -1, -1};

    for (int i = 0; i < wallpaper.size(); i++)
    {
        string row = wallpaper[i];
        for (int j = 0; j < row.size(); j++)
        {
            if (row[j] == '#')
            {
                if (answer[0] < 0 || answer[0] > i)
                {
                    answer[0] = i;
                }

                if (answer[1] < 0 || answer[1] > j)
                {
                    answer[1] = j;
                }

                if (answer[2] < 0 || answer[2] < i + 1)
                {
                    answer[2] = i + 1;
                }

                if (answer[3] < 0 || answer[3] < j + 1)
                {
                    answer[3] = j + 1;
                }
            }
        }
    }
    
    return answer;
}