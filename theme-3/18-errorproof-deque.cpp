#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <array>
#include <list>

int main()
{
    const int ARRAYSIZE = 30;
    std::list<std::array<int, ARRAYSIZE>> arrayList;
    arrayList.push_back(std::array<int, ARRAYSIZE> {});
    auto iterFront = arrayList.begin();
    auto iterBack = arrayList.begin();
    int indexFront = 0;
    int indexBack = -1;
    int currentSize = 0;


    int inputInt;
    std::string command;
    while (std::cin >> command)
    {
        if (command == "push_front")
        {
            std::cin >> inputInt;
            currentSize++;

            indexFront--;
            if (indexFront < 0)
            {
                arrayList.push_front(std::array<int, ARRAYSIZE> {});
                iterFront--;
                indexFront = ARRAYSIZE - 1;
                (*iterFront)[indexFront] = inputInt;
            }
            else
            {
                (*iterFront)[indexFront] = inputInt;
            }

            if (indexBack == -1)
            {
                indexBack = indexFront;
                iterBack = iterFront;
            }

            std::cout << "ok\n";
        }
        else if (command == "push_back")
        {
            std::cin >> inputInt;
            currentSize++;

            if (indexBack == -1)
            {
                indexFront = 0;
                iterFront = iterBack;
            }

            indexBack++;
            if (indexBack > ARRAYSIZE - 1)
            {
                arrayList.push_back(std::array<int, ARRAYSIZE> {});
                iterBack++;
                indexBack = 0;
                (*iterBack)[indexBack] = inputInt;
            }
            else 
            {
                (*iterBack)[indexBack] = inputInt;
            }

            std::cout << "ok\n";
        }
        else if (command == "pop_front")
        {
            if (currentSize == 0)
            {
                std::cout << "error\n";
                continue;
            }

            std::cout << (*iterFront)[indexFront] << '\n';
            
            indexFront++;
            currentSize--;

            if (indexFront > ARRAYSIZE - 1)
            {
                iterFront++;
                indexFront = 0;
                arrayList.pop_front();
            }

            if (currentSize == 0)
            {
                indexFront = 0;
                indexBack = -1;
                iterFront = arrayList.begin();
                iterBack = arrayList.begin();
            }
        }
        else if (command == "pop_back")
        {
            if (currentSize == 0)
            {
                std::cout << "error\n";
                continue;
            }

            std::cout << (*iterBack)[indexBack] << '\n';
            
            indexBack--;
            currentSize--;

            if (indexBack < 0)
            {
                iterBack--;
                indexBack = ARRAYSIZE - 1;
                arrayList.pop_back();
            }

            if (currentSize == 0)
            {
                indexFront = 0;
                indexBack = -1;
                iterFront = arrayList.begin();
                iterBack = arrayList.begin();
            }
        }
        else if (command == "front")
        {
            if (currentSize == 0)
            {
                std::cout << "error\n";
                continue;
            }

            std::cout << (*iterFront)[indexFront] << '\n';
        }
        else if (command == "back")
        {
            if (currentSize == 0)
            {
                std::cout << "error\n";
                continue;
            }
            std::cout << (*iterBack)[indexBack] << '\n';
        }
        else if(command == "pop_back")
        {
            if (currentSize == 0)
            {
                std::cout << "error\n";
                continue;
            }

            std::cout << (*iterBack)[indexBack] << '\n';
            currentSize--;

            if (indexBack == 0)
            {
                iterBack--;
                indexBack = ARRAYSIZE - 1;
                arrayList.pop_back();
            }
            else
            {
                indexBack--;
            }
        }
        else if(command == "front")
        {
            if (currentSize == 0)
            {
                std::cout << "error\n";
                continue;
            } 

            std::cout << (*iterFront)[indexFront] << '\n';
        }
        else if(command == "back")
        {
            if (currentSize == 0)
            {
                std::cout << "error\n";
                continue;
            }

            if (indexBack == -1)
            {
                std::cout << (*iterFront)[indexFront] << '\n';
                continue;
            }

            std::cout << (*iterBack)[indexBack] << '\n';
        }
        else if (command == "size") 
        {
            std::cout << currentSize << '\n';
        }
        else if (command == "clear") 
        {
            arrayList.clear();
            arrayList = {std::array<int, ARRAYSIZE> {}};
            iterFront = arrayList.begin();
            iterBack = arrayList.begin();
            indexFront = 0;
            indexBack = -1;
            currentSize = 0;
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
