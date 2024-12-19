#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++)
    {
        int weapon_power = 0;

        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                weapon_power++;

                if ((i / j) != j)
                {
                    weapon_power++;
                }
            }

        }

        answer += weapon_power > limit? power : weapon_power;
    }
    
    return answer;
}