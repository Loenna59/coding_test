#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

struct coord
{
    int x;
    int y;

    void print()
    {
        std::cout << x << " " << y << "\n";
    }

    static coord create(const std::string& str)
    {
        coord c;

        std::istringstream ss(str);

        std::vector<int> buffers;
        std::string token;

        while (ss >> token)
        {
            buffers.push_back(std::stoi(token));
        }

        c.x = buffers[0];
        c.y = buffers[1];

        return c;
    }

    static bool compare(const coord& a, const coord& b)
    {
        if (a.y == b.y)
        {
            return a.x < b.x;
        }

        return a.y < b.y;
    }
};

int main()
{

    int N;
    std::cin >> N;
    std::cin.ignore();

    std::vector<coord> coords;

    std::string input;
    
    for (int i = 0; i < N; i++)
    {
        getline(std::cin, input);
        coords.push_back(coord::create(input));
    }

    std::sort(coords.begin(), coords.end(), coord::compare);

    for (coord c : coords)
    {
        c.print();
    }

    return 0;
}