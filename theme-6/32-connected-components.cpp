#include <iostream>
#include <vector>
#include <stack>

void dfs(const std::vector<std::vector<int>>& graph, std::vector<int>& visited, int now, int comp)
{
    visited[now] = comp;
    for (int neighbour : graph[now])
    {
        if (visited[neighbour] == -1)
        {
            dfs(graph, visited, neighbour, comp);
        }
    }
}

int main() 
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) 
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<int> visited(n + 1, -1);

    int compCount = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (visited[i] == -1) 
        {
            dfs(graph, visited, i, compCount);
            compCount++;
        }
    }

    std::cout << compCount << '\n';
    std::vector<std::vector<int>> components(compCount);
    for (int i = 1; i <= n; i++) 
    {
        components[visited[i]].push_back(i);
    }
    for (int i = 0; i < compCount; i++) 
    {
        std::cout << components[i].size() << '\n';
        for (int j = 0; j < components[i].size(); j++) 
        {
            std::cout << components[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}