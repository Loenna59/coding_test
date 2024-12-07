#include <iostream>

int main()
{
    int a;
    int b;
    
    while (true)
    {
        std::cin >> a >> b;

        if (std::cin.eof() == true)
        {
            break;
        }
        
        std::cout << a + b << std::endl;
    }
    
    return 0;
}