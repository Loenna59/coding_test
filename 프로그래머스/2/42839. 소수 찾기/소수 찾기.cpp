#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

void swap(char& a, char& b)
{
    char tmp = a;
    a = b;
    b = tmp;
}

void permutation(string& str, int depth, int n, int r, set<int>& result)
{
    if (depth == r)
    {
        string num_str = "";
        for (int i = 0; i < r; i++)
        {
            num_str.push_back(str[i]);
        }

        int num = stoi(num_str);
        result.insert(num);

        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(str[depth], str[i]);
        permutation(str, depth + 1, n, r, result);
        swap(str[depth], str[i]);
    }
}

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> primes;

    for (int i = 1; i <= numbers.size(); i++)
    {
        set<int> nums;
        permutation(numbers, 0, numbers.size(), i, nums);

        for (int num : nums)
        {
            if (is_prime(num) && primes.find(num) == primes.end())
            {
                primes.insert(num);
                answer++;
            }
        }

    }

    return answer;
}