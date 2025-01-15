#include <iostream>
#include <string>

using namespace std;

int main()
{
    string result;

    while (true)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            break;
        }

        string str = to_string(input);
        int half = str.size() / 2;

        string front = str.substr(0, half);
        string back(str.rbegin(), str.rbegin() + half);

        string answer = "yes";

        for (int i = 0; i < front.size(); i++)
        {
            if (front[i] != back[i])
            {
                answer = "no";
                break;
            }
        }

        if (!result.empty())
        {
            result.append("\n");
        }

        result.append(answer);
    }
    
    cout << result;

    return 0;
}