#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ifstream file;
    file.open("input.txt");
    int height, width;
    file >> height >> width;
    std::vector<std::vector<int>> priceMatrix (height, std::vector<int> (width));
    std::vector<std::vector<int>> currentMatrix (height, std::vector<int> (width, 999));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            file >> priceMatrix[i][j];
        }
    }

    currentMatrix[0][0] = priceMatrix[0][0];
    for (int i = 1; i < height; i++)
    {
        currentMatrix[i][0] = currentMatrix[i-1][0] + priceMatrix[i][0];
    }
    for (int j = 1; j < width; j++)
    {
        currentMatrix[0][j] = currentMatrix[0][j-1] + priceMatrix[0][j];
    }

    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            currentMatrix[i][j] = std::min(currentMatrix[i-1][j], currentMatrix[i][j-1]) + priceMatrix[i][j];
        }
    }

    std::cout << currentMatrix[height - 1][width - 1];

    return 0;
}