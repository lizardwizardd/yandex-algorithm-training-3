#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <fstream>
#include <utility>
#include <vector>

int main()
{

    std::ifstream file;
    file.open("input.txt");

    std::map<char, int> freq;
    char input;

    while (file) 
    {
        input = file.get();

        if (input == ' ' || input == '\n')
        {
            continue;
        }
        
        freq[input]++;
    }
    std::vector <std::pair<char, int>> histogram;

    int maxCount = 0;
    int elementCount = 0;

    for(auto iter = std::next(freq.begin()); iter != freq.end(); iter++)
    {
        histogram.push_back({iter -> first, iter -> second});

        maxCount = std::max(maxCount, iter->second);
        elementCount++;
    }

    for (int i = 0; i < maxCount; i++)
    {
        for(int j = 0; j != elementCount; j++)
        {
            if (maxCount - histogram[j].second > 0)
            {
                std::cout << ' ';
            } 
            else 
            {
                std::cout << '#';
            }
            histogram[j].second++;
        }
        std::cout << '\n';
    }

    for (auto elem : histogram)
    {
        std::cout << elem.first;
    }

    return 0;
}

