#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; // 저장된 사이트 주소 수
    int m; // 비밀번호를 찾으려는 사이트 주소의 수

    std::cin >> n >> m;

    std::unordered_map<std::string, std::string> pwds;

    for (int i = 0; i < n; i++)
    {
        std::string key;
        std::cin >> key;
        std::cin >> pwds[key];
    }

    std::vector<std::string> answers(m);

    for (int i = 0; i < m; i++)
    {
        std::string key;
        std::cin >> key;
        answers[i] = pwds[key];
    }
    

    for (int i = 0; i < m; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }
        
        std::cout << answers[i];
    }

    return 0;
}