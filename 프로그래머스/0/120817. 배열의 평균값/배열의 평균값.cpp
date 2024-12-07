#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    
    int sum = 0;
    int count = count = numbers.size();
    
    for (int i = 0; i < count; i++)
    {
        sum += numbers[i];
    }
    
    return sum / (double)count;
}