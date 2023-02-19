#include <iostream>
#include <utility>
#include <vector>

int main()
{
    int coordCount;
    std::cin >> coordCount;

    int inputX;
    int inputY;
    int minX, minY, maxX, maxY;
    minX = minY = 999999999;
    maxX = maxY = -999999999;

    for (int i = 0; i != coordCount; i++) 
    {
        std::cin >> inputX;
        std::cin >> inputY;

        minX = std::min(minX, inputX);
        maxX = std::max(maxX, inputX);

        minY = std::min(minY, inputY);
        maxY = std::max(maxY, inputY);
    }

    std::cout << minX << " " << minY << " " << maxX << " " << maxY;

    return 0;
}