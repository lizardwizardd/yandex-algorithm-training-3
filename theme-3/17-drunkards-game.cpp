#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::queue<int> deck1;
    std::queue<int> deck2;

    int input;
    for (int i = 0; i != 5; i++)
    {
        std::cin >> input;
        deck1.push(input);
    }

    for (int i = 0; i != 5; i++)
    {
        std::cin >> input;
        deck2.push(input);
    }

    int turnsCount = 0;

    while (!deck1.empty() && !deck2.empty() && turnsCount <= 1000000)
    {
        turnsCount++;
        if ((deck1.front() > deck2.front() && !(deck1.front() == 9 && deck2.front() == 0)) || (deck1.front() == 0 && deck2.front() == 9))
        {
            deck1.push(deck1.front());
            deck1.push(deck2.front());
            deck1.pop();
            deck2.pop();
        }
        else 
        {
            deck2.push(deck1.front());
            deck2.push(deck2.front());
            deck1.pop();
            deck2.pop();
        }
    }

    if (deck1.empty())
    {
        std::cout << "second " << turnsCount;
    }
    else if (deck2.empty()) 
    {
        std::cout << "first " << turnsCount;
    }
    else
    {
        std::cout << "botva";
    }

    return 0;
}