#include <iostream>

int calculate_score(int t, int f, int s, int p, int c)
{
    return t * 6 + f * 3 + s * 2 + p + c * 2;
}

int main()
{    
    int t; 
    int f; 
    int s; 
    int p; 
    int c;

    std::cin >> t >> f >> s >> p >> c;
    
    int score1 = calculate_score(t, f, s, p, c);
    
    std::cin >> t >> f >> s >> p >> c;
    
    int score2 = calculate_score(t, f, s, p, c);

    std::cout << score1 << " " << score2;

    return 0;
}