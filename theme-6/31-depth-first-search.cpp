#include <algorithm>
#include <vector>
#include <iostream>

void dfs(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int now)
{
    visited[now] = true;
    for (auto neighbour : graph[now])
    {
        if (!visited[neighbour])
        {
            dfs(graph, visited, neighbour);
        }
    }
}

int main()
{
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> adjacencyList(V + 1);
    for (int i = 0; i < E; i++)
    {
        int A, B;
        std::cin >> A >> B;
        adjacencyList[A].emplace_back(B);
        adjacencyList[B].emplace_back(A);
    }

    std::vector<bool> visited(V + 1);
    dfs(adjacencyList, visited, 1);

    std::cout << std::count(visited.begin(), visited.end(), true) << '\n';
    for (int i = 1; i <= V; i++)
    {
        if (visited[i])
        {
            std::cout << i << ' ';
        }
    }

    return 0;
}
