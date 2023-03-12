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
    std::vector<int> prevArray (V + 1, -1);
    int prev = -1;
    visited[start] = 0;

    queue.push_back(start);
    while (!queue.empty())
    {
        now = queue.front();
        queue.pop_front();
        prev = now;
        for (auto neighbor : graph[now])
        {
            if (visited[neighbor] == 999999)
                queue.push_back(neighbor);
            if (visited[now] + 1 < visited[neighbor])
            {
                visited[neighbor] = visited[now] + 1;
                prevArray[neighbor] = prev;
            }
        }
    }

    if (visited[finish] == 999999)
    {
        std::cout << -1 << '\n';
    }
    else 
    {
        std::cout << visited[finish] << '\n';
        if (visited[finish] != 0)
        {
            while (finish != -1)
            {
                queue.push_front(finish);
                finish = prevArray[finish];
            }
            
            for (auto x : queue)
            {
                std::cout << x << ' '; 
            }
        }
    }
    
    return 0;
}
