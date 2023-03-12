#include <utility>
#include <vector>
#include <iostream>

int main()
{
    long long M, N;
    std::cin >> M >> N;

    std::vector<std::pair<long long, long long>> installed;

    int inputs = N;
    int left, right;
    while (inputs-- > 0)
    {
        std::cin >> left >> right;

        for (size_t i = 0; i < installed.size(); i++)
        {
            if (installed[i].first <= right && left <= installed[i].second)
            {
                installed[i].first = -1;
                installed[i].second = -1;
            }
        }
        installed.push_back({left, right});
    }

    int result = 0;
    for (size_t i = 0; i < installed.size(); i++)
    {
        if (installed[i].first != -1)
        {
            result++;
        }
    }
    std::cout << result;
}
