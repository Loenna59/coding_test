#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<int> stack;

    int n;
    std::cin >> n;
    std::cin.ignore();

    std::string answer;

    for (int i = 0; i < n; i++)
    {
        std::string command;
        getline(std::cin, command);

        size_t index = command.find(' ');

        if (index != std::string::npos)
        {
            std::string num_str = command.substr(index + 1);
            stack.push(std::stoi(num_str));
            continue;
        }

        if (!answer.empty())
        {
            answer.append("\n");
        }

        switch (command[0])
        {
        case 'p':
            if (stack.empty())
            {
                answer.append("-1");
            }
            else
            {
                int pop = stack.top();
                stack.pop();
                answer.append(std::to_string(pop));
            }
            break;
        case 's':
            answer.append(std::to_string(stack.size()));
            break;
        case 'e':
            answer.append(std::to_string(stack.empty()));
            break;
        case 't':
            answer.append((stack.empty()? "-1" : std::to_string(stack.top())));
            break;
        default:
            break;
        }
    }

    std::cout << answer;

    return 0;
}