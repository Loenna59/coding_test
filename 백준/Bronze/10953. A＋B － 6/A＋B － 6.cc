#include <iostream>
#include <string>
#include <vector>

int main()
{
    int num;
    std::cin >> num;

    std::vector<std::string> vec;

    for (int i = 0; i < num; i++)
    {
        std::string str;
        std::cin >> str;
        vec.push_back(str);
    }
    
    std::string seperator = ",";

    for (int i = 0; i < num; i++)
    {
        int cur_positon = 0;
        int position;
        
        std::string str = vec[i];
        std::vector<int> nums;
        
        while (true)
        {
            position = str.find(seperator, cur_positon);
            if (position == str.npos)
            {
                std::string end_str = str.substr(cur_positon);
                nums.push_back(std::stoi(end_str));
                break;
            }
            
            int len = position - cur_positon;

            std::string substr = str.substr(cur_positon, len);
            nums.push_back(std::stoi(substr));

            cur_positon = position + 1;
        }

        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        std::cout << sum << std::endl;
    }
    
    return 0;
}