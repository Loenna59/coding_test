#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());

    do
    {
        int remain = k;
        int count = 0;
        for (int i = 0; i < dungeons.size(); i++)
        {
            if (dungeons[i][0] > remain)
            {
                break;
            }

            count++;
            remain -= dungeons[i][1];
        }

        if (answer < count)
        {
            answer = count;
        }

    } while (next_permutation(dungeons.begin(), dungeons.end()));
    

    return answer;
}