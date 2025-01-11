#include <iostream>
#include <string>
#include <cstdio>

int main()
{
    int a;
    int b;
    int c;

    std::cin >> a >> b >> c;
    
    std::cout << a + b - c << "\n";

    char* char_a = new char[33];
    char* char_b = new char[33];

    // itoa(a, char_a, 10);
    // itoa(b, char_b, 10);

    sprintf(char_a, "%d", a);
    sprintf(char_b, "%d", b);

    std::string str(char_a);
    str.append(char_b);

    std::cout << std::stoi(str) - c;

    return 0;
}