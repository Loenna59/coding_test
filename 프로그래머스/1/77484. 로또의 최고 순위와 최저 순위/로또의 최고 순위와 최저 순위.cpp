#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {    
    int best = 0;
    int worst = 0;
    
    for (int num : lottos)
    {
        if (num == 0)
        {
            best++;
            continue;
        }

        if (any_of(win_nums.begin(), win_nums.end(), [num](int i) { return num == i; }))
        {
            worst++;
        }
    }

    best = min(7 - (best + worst), 6);
    worst = min(7 - worst, 6);
    
    return vector<int>({best, worst});
}