#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int queueLength;
    std::cin >> queueLength;
    std::vector<std::vector<int>> buyTime (queueLength + 3, std::vector<int> (3, 9999));
    std::vector<int> currentTime(queueLength + 3, 0);

    for (int i = 3; i < queueLength + 3; i++)
    {
        std::cin >> buyTime[i][0] >> buyTime[i][1] >> buyTime[i][2];
    }

    for (int i = 3; i < queueLength + 3; i++)
    {
        currentTime[i] = std::min({currentTime[i-1] + buyTime[i][0], currentTime[i-2] + buyTime[i-1][1], currentTime[i-3] + buyTime[i-2][2]});
    }

    std::cout << currentTime.back();

    return 0;
}