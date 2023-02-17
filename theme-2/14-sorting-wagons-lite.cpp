#include <iostream>
#include <stack>

int main()
{
    int wagonCount;
    std::cin >> wagonCount;

    bool sortable = true;

    std::stack<int> deadend;
    std::stack<int> train;

    int nextWagon = 1;

    int wagon;
    std::cin >> wagon;
    for (int wagonsProcessed = 0; wagonsProcessed < wagonCount;)
    {
        if (!deadend.empty() && deadend.top() == nextWagon)
        {
            //std::cout << "pushed " << deadend.top() << " from deadend to train\n";
            train.push(deadend.top());
            deadend.pop();
            nextWagon++;
        }
        else if(wagon == nextWagon)
        {
            //std::cout << "pushed " << wagon << " from input to train\n";
            train.push(wagon);
            nextWagon++;
            wagonsProcessed++;
            if (wagonsProcessed < wagonCount)
                std::cin >> wagon;
        }
        else if((!deadend.empty() && deadend.top() > wagon) || deadend.empty())
        {
            //std::cout << "pushed " << wagon << " from input to deadend\n";
            deadend.push(wagon);
            wagonsProcessed++;
            if (wagonsProcessed < wagonCount)
                std::cin >> wagon;
        }
        else 
        {
            sortable = false;
            break;
        }
    }

    if (sortable)
        std::cout << "YES";
    else
        std::cout << "NO";
}