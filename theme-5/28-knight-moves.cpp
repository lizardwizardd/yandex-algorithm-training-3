#include <iostream>
#include <vector>

int main()
{
    int height, width;
    std::cin >> height >> width;
    std::vector<std::vector<unsigned long>> moveCountMatrix (height + 2, std::vector<unsigned long> (width + 2));
    moveCountMatrix[2][2] = 1;
    
    for (int i = 2; i != height + 2; i++)
    {
        for (int j = 2; j != width + 2; j++)
        {
            if (i == 2 && j == 2)
                continue;
            moveCountMatrix[i][j] = moveCountMatrix[i-2][j-1] + moveCountMatrix[i-1][j-2];
        }
    }

    std::cout << moveCountMatrix[height + 1][width + 1];
}