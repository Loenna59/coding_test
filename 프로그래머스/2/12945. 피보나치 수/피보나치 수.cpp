#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int* arr = new int[n + 1];

    arr[0] = 0;
    arr[1] = 1;

    if (n == 2)
    {
        delete[] arr;
        return 1;
    }

    for (int i = 2; i < n + 1; i++)
    {
        arr[i] = (arr[i - 2] % 1234567) + (arr [i - 1] % 1234567);
    }
    
    answer = arr[n] % 1234567;
    
    delete[] arr;
    
    return answer;
}