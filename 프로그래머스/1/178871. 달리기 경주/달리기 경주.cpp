#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> map;

    for (int i = 0; i < players.size(); i++)
    {
        map.insert({players[i], i});
    }

    for (string calling : callings)
    {
        int index = map[calling];
        if (index > 0)
        {
            swap(players[index], players[index - 1]);

            map[players[index]] = index;
            map[players[index - 1]] = index - 1;
        }
    }

    return players;
}