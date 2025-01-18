#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::queue<int> queue;

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
            queue.push(std::stoi(num_str));
            continue;
        }

        if (!answer.empty())
        {
            answer.append("\n");
        }

        switch (command[0])
        {
        case 'p':
            if (queue.empty())
            {
                answer.append("-1");
            }
            else
            {
                int pop = queue.front();
                queue.pop();
                answer.append(std::to_string(pop));
            }
            break;
        case 's':
            answer.append(std::to_string(queue.size()));
            break;
        case 'e':
            answer.append(std::to_string(queue.empty()));
            break;
        case 'f':
            answer.append((queue.empty()? "-1" : std::to_string(queue.front())));
            break;
        case 'b':
            answer.append((queue.empty()? "-1" : std::to_string(queue.back())));
            break;
        default:
            break;
        }
    }

    std::cout << answer;

    return 0;
}
