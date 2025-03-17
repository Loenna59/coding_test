#include <iostream>
#include <sstream>
#include <vector>

// -가 등장하면 이후 숫자들을 최대한 크게 만들어야한다.
// 첫 -가 나온 이후의 숫자들은 전부 하나의 그룹으로 묶어서 빼는 것이 최적
// - 기준으로 분리 => 그룹별로 더하고 전부 빼기

int main()
{
    std::string s;

    std::cin >> s;

    std::istringstream iss(s);

    std::vector<std::string> groups;

    std::string token;

    while (std::getline(iss, token, '-'))
    {
        groups.push_back(token);
    }

    std::vector<int> numbers;

    for (int i = 0, size = groups.size(); i < size; i++)
    {
        std::istringstream iss(groups[i]);
        
        int n;
        int sum = 0;

        while (iss >> n)
        {
            sum += n;
        }
        
        numbers.push_back(sum);
    }

    int result = numbers[0];

    for (int i = 1, size = numbers.size(); i < size; i++)
    {
        result -= numbers[i];
    }

    std::cout << result;

    return 0;
}