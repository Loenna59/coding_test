#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int min_num = min(n, m);
    int max_num = max(n, m);

    int gcd = 1;

    for (int i = 1; i <= max_num; i++)
    {
        if (n % i == 0 && m % i == 0)
        {
            gcd = i;
        }
    }

    answer = vector<int>({gcd, gcd * (n / gcd) * (m / gcd)});

    return answer;
}