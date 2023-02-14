#include <queue>
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <map>

int main()
{
    std::set<int> collection;
    std::vector<int> buyers;
    std::map<int, int> cardNums;

    std::fstream file;
    file.open("input.txt");
    int N, K, inputNumber;
    
    file >> N;
    while (N-- > 0)
    {
        file >> inputNumber;
        collection.insert(inputNumber);
    }

    file >> K;
    while (K-- > 0)
    {
        file >> inputNumber;
        buyers.push_back(inputNumber);
        cardNums[inputNumber]++;
    }

    int countElements = 0;
    auto iter = collection.begin();
    for (auto [num, cardcount] : cardNums)
    {
        while (*iter < num)
        {
            if(iter == collection.end())
            {
                cardNums[num] = countElements;                
                break;
            }
            iter++;
            countElements++;
        }

        if(*iter >= num)
        {
            cardNums[num] = countElements; 
        }
    }

    for (auto elem : buyers)
    {
        std::cout << cardNums[elem] << '\n';
    }

    return 0;
}