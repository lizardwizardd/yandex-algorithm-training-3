#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>


int main()
{
    int V;
    std::cin >> V;

    std::vector<std::vector<int>> graph (V + 1);
    std::vector<int> pathLengths (V + 1, -1);

    for (int i = 1; i < V + 1; i++)
    {
        int now = 0;
        for (int j = 1; j < V + 1; j++)
        {
            std::cin >> now;
            if (now == 1)
            {
                graph[i].push_back(j);
            }
        }
    }
    int start;
    int finish;
    std::cin >> start >> finish;

    int now;
    std::deque<int> queue;
    std::vector<int> visited (V + 1, 999999);
    visited[start] = 0;

    queue.push_back(start);
    while (!queue.empty())
    {
        now = queue.front();
        queue.pop_front();
        for (auto neighbor : graph[now])
        {
            if (visited[neighbor] == 999999)
                queue.push_back(neighbor);
            visited[neighbor] = std::min(visited[now] + 1, visited[neighbor]);
        }
    }

    if (visited[finish] == 999999)
    {
        std::cout << -1 << '\n';
    }
    else 
    {
        std::cout << visited[finish];
    }
    
    return 0;
}
