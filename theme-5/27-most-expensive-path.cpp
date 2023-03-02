#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
    std::ifstream file;
    file.open("input.txt");
    int height, width;
    file >> height >> width;
    std::vector<std::vector<int>> priceMatrix (height, std::vector<int> (width));
    std::vector<std::vector<int>> currentMatrix (height, std::vector<int> (width, 999));
    std::vector<std::vector<std::string>> pathMatrix (height, std::vector<std::string> (width));

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
        pathMatrix[i][0] += pathMatrix[i-1][0] + "D ";
    }
    for (int j = 1; j < width; j++)
    {
        currentMatrix[0][j] = currentMatrix[0][j-1] + priceMatrix[0][j];
        pathMatrix[0][j] = pathMatrix[0][j-1] + "R ";
    }

    for (int i = 1; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            if (currentMatrix[i-1][j] > currentMatrix[i][j-1])
            {
                currentMatrix[i][j] =  priceMatrix[i][j] + currentMatrix[i-1][j];
                pathMatrix[i][j] += pathMatrix[i-1][j] + "D ";
            }
            else 
            {
                currentMatrix[i][j] =  priceMatrix[i][j] + currentMatrix[i][j-1];
                pathMatrix[i][j] = pathMatrix[i][j-1] + "R ";
            }
        }
    }

    std::cout << currentMatrix[height - 1][width - 1] << '\n' << pathMatrix[height - 1][width - 1];

    return 0;
}

