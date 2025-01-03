#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer{};

    const int max_day = 28;
    const int max_month = 12;
    
    string format = "%Y.%m.%d";

    tm today_tm;
    istringstream today_ss(today);
    today_ss >> get_time(&today_tm, format.c_str());
    
    map<string, int> term_map;

    for (string term : terms)
    {   
        size_t split = term.find(" ");
        string num = term.substr(split + 1);
        term_map.insert({term.substr(0, split), stoi(num) * max_day});
    }

    for (int i = 0; i < privacies.size(); i++)
    {
        string privacy = privacies[i];
        size_t split = privacy.find(" ");
        string date_time = privacy.substr(0, split);
        string term = privacy.substr(split + 1);

        tm tm = {};
        istringstream ss(date_time);
        ss >> get_time(&tm, format.c_str());

        int days = today_tm.tm_mday - tm.tm_mday;
        int months = today_tm.tm_mon - tm.tm_mon;
        int years = today_tm.tm_year - tm.tm_year;

        int period = years * max_month * max_day + months * max_day + days;

        if (period >= term_map[term])
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}