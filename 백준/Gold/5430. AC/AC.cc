#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int t;

    std::cin >> t;

    for (int _ = 0; _ < t; _++)
    {
        if (_ > 0)
        {
            std::cout << "\n";
        }

        std::string p;
        std::cin >> p;

        int n;
        std::cin >> n;

        std::string str;
        std::cin >> str;

        std::istringstream st(str.substr(1, str.size() - 2));

        std::vector<int> x;

        for (std::string i; st.getline(&i[0], 4, ',');)
        {
            int digit = std::isdigit(i[0]);

            if (digit != 0)
            {
                int num = std::stoi(i);
                x.push_back(num);
            }
        }

        bool is_reverse = false;
        int pop_front_count = 0;
        int pop_back_count = 0;

        for (int i = 0, count = p.size(); i < count; i++)
        {
            char ch = p[i];
            if (ch == 'R')
            {
                is_reverse = !is_reverse;
            }

            if (ch == 'D')
            {
               if (is_reverse)
               {
                    pop_back_count++;
               }
               else
               {
                    pop_front_count++;
               }
            }
        }

        if (pop_front_count + pop_back_count > x.size())
        {
            std::cout << "error";
            continue;
        }
        
        std::cout << "[";

        if (is_reverse)
        {
            for (std::vector<int>::reverse_iterator rit = x.rbegin() + pop_back_count; rit != x.rend() - pop_front_count; ++rit)
            {
                if (rit > x.rbegin() + pop_back_count)
                {
                    std::cout << ",";
                }

                int i = *rit;
                std::cout << i;
            }
            
        }
        else
        {
            for (std::vector<int>::iterator it = x.begin() + pop_front_count; it != x.end() - pop_back_count; ++it)
            {
                if (it > x.begin() + pop_front_count)
                {
                    std::cout << ",";
                }

                int i = *it;
                std::cout << i;
            }
        }

        std::cout << "]";
    }

    return 0;
}