#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    int count = 0; 
    int num = 666; 

    while (true) {
        if (std::to_string(num).find("666") != std::string::npos) 
        { 
            count++;
            if (count == n) { 
                break;
            }
        }
        num++;
    }

    std::cout << num;

    return 0;
}