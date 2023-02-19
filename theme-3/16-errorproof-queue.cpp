#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> queue;

    int headIndex = 0;

    int inputInt;
    std::string command;
    while (std::cin >> command)
    {
        if (command == "push")
        {
            std::cin >> inputInt;
            queue.push_back(inputInt);
            std::cout << "ok\n";
        }
        else if (command == "pop")
        {
            if (queue.size() - headIndex < 1)
            {
                std::cout << "error\n";
                continue;
            }
            std::cout << queue[headIndex] << '\n';
            headIndex++;
        }
        else if (command == "front") 
        {
            if (queue.size() - headIndex < 1)
            {
                std::cout << "error\n";
                continue;
            }
            std::cout << queue[headIndex] << '\n';
        }
        else if (command == "size") 
        {
            std::cout << queue.size() - headIndex << '\n';
        }
        else if (command == "clear") 
        {
            queue.clear();
            headIndex = 0;
            std::cout << "ok\n";
        }
        else if (command == "exit") 
        {
            std::cout << "bye\n";
            break;
        }
    }

    return 0;
}