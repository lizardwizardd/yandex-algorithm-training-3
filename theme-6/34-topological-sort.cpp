#include <iostream>
#include <vector>
#include <stack>

std::vector<int> result;
std::vector<int> color;

bool dfs(const std::vector<std::vector<int>>& graph, int now)
{
    color[now] = 1;

    for (int neighbour : graph[now])
    {
        if (color[neighbour] == 0)
        {
            if (dfs(graph, neighbour)) return true;
        }
        else if (color[neighbour] == 1) return true;
    }
    color[now] = 2;
    result.push_back(now);
    return false;
}

int main() 
{
    int V, E;
    std::cin >> V >> E;

    color.resize(V + 1);
    std::vector<std::vector<int>> graph(V + 1);
    for (int i = 0; i < E; i++) 
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i < V + 1; i++)
    {
        if (color[i] == 0)
        {
            if (dfs(graph, i))
            {
                std::cout << "-1\n";
                return 0;
            }
            
        } 
    }

    for (int x = (int)result.size() - 1; x >= 0; x--)
    {
        std::cout << result[x] << ' ';
    }
    return 0;
}