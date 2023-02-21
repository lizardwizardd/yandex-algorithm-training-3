//
// INCORRECT SOLUTION, 
// WRONG ANSWER FOR SOME CASES
//
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

int main()
{
    int diskSize;
    int coordsCount;
    std::cin >> diskSize >> coordsCount;

    std::vector<std::pair<int, int>> coords;

    int inputStart;
    int inputEnd;
    for (int i = 0; i < coordsCount; i++)
    {
        std::cin >> inputStart >> inputEnd;
        coords.push_back({inputStart, inputEnd});
    }

    std::sort(coords.begin(), coords.end());

    
    std::cout << "xx\n";
    for (auto [i1, i2] : coords)
    {
        std::cout << i1 << " " << i2 << '\n';
    }
    

    for (size_t i = 1; i < coords.size(); i++)
    {
        if (coords[i-1].second >= coords[i].first)
        {
            coords[i-1].second = std::max(coords[i-1].second, coords[i].second);
            coords.erase(coords.begin() + i);
            coordsCount--;
            i--;
        }
    }

    
    std::cout << "xx\n";
    for (auto [i1, i2] : coords)
    {
        std::cout << i1 << " " << i2 << '\n';
    }
    
    std::cout << coordsCount;

    return 0;
}