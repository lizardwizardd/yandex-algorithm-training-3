#include <iostream>
#include <vector>
#include <stack>

int dfs(const std::vector<std::vector<int>>& graph, std::vector<int>& visited, int now, int color)
{
    visited[now] = color;
    for (auto neighbour : graph[now])
    {
        if (visited[neighbour] == -1)
        {
            dfs(graph, visited, neighbour, 3 - color);
        }
        else if (visited[neighbour] == color)
        {
            return 1;
        }
    }
    return 0;
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
            if(dfs(graph, visited, i, compCount) == 1)
            {
                std::cout << "NO";
                return 0;
            }
            compCount++;
        }
    }

    std::cout << "YES";
    
    return 0;
}