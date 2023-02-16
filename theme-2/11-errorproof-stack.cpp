#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream file;
    file.open("input.txt");

    std::vector<int> stack;

    std::string command;
    int pushNumber;
    while(file >> command)
    {
        if (command == "push")
        {
            file >> pushNumber;
            stack.push_back(pushNumber);
            std::cout << "ok" << '\n';
        }
        else if (command == "size")
        {
            std::cout << stack.size() << '\n';
        }
        else if (command == "pop")
        {
            if (!stack.empty())
            {
                std::cout << stack[stack.size() - 1] << '\n';
                stack.pop_back();
            } 
            else 
            {
                std::cout << "error" << '\n';
            }
            
        }
        else if (command == "back") 
        {
            if (!stack.empty())
            {
                std::cout << stack[stack.size() - 1] << '\n';
            }
            else
            {
                std::cout << "error" << '\n';
            }
        }  
        else if (command == "clear") 
        {
            stack.clear();
            std::cout << "ok" << '\n';
        }
        else if (command == "exit") 
        {
            std::cout << "bye";
            break;
        }
    }

    return 0;
}