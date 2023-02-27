#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> lineLength(N);
    std::vector<int> nailsCoords(N);
    for (int i = 0; i != N; i++)
    {
        std::cin >> nailsCoords[i];
    }
    std::sort(nailsCoords.begin(), nailsCoords.end());

    lineLength[1] = nailsCoords[1] - nailsCoords[0];
    lineLength[2] = nailsCoords[2] - nailsCoords[0];
    for (int i = 3; i < N; i++)
    {
        lineLength[i] = std::min(lineLength[i-1], lineLength[i-2]) + nailsCoords[i] - nailsCoords[i-1];
    }
    std::cout << lineLength.back();

    return 0;
}