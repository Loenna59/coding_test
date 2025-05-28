#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::string keyword = "nemo";

    std::vector<bool> answers;
   
    while (true)
    {
        std::string input;

        std::getline(std::cin, input);
        
        if (input == "EOI")
        {
            break;
        }
        
        std::string lower(input.size(), ' ');

        std::transform(input.begin(), input.end(), lower.begin(), ::tolower);

        answers.push_back(lower.find(keyword) != std::string::npos);
    }

    for (int i = 0, count = answers.size(); i < count; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }

        std::cout << (answers[i]? "Found" : "Missing");
    }
    
    return 0;
}
