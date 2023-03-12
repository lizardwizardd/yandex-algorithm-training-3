#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <limits>
 
using namespace std;
 
int n;
vector<vector<vector<int> > > matrix;
struct coords
{
    int x,y,z;
    coords(){}
    coords(int Z, int X, int Y)
    {
        z = Z; x = X; y = Y;
    }
};
coords start;
void input()
{
    cin >> n;
    matrix = vector<vector<vector<int> > >(n,vector<vector<int> >(n,vector<int>(n,0)));
    char c;
    for (int z = 0; z < n; z++)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                cin >> c;
                if (c == 'S')
                    start = coords(z,x,y);
                matrix[z][x][y] = (c == '#' ? 1 : 0);
            }
        }
    }           
}

int moveX[6] = {0 ,0, 0,0,-1,1};
int moveY[6] = {0 ,0,-1,1, 0,0};
int moveZ[6] = {-1,1, 0,0, 0,0};

bool correct(int z, int x, int y)
{
    if (z<0 || x<0 || y <0 || z==n || x==n || y==n)
        return false;
    else
        return true;
}

void BFS()
{
    int steps = -1;
    int init = 2;
    queue<coords> queue;
    matrix[start.z][start.x][start.y] = init;
    queue.push(start);
    while (!queue.empty())
    {
        coords now = queue.front();
        queue.pop();
        
        if (now.z == 0)
        {
            steps = matrix[now.z][now.x][now.y];
            break;
        }
        
        for (int i = 0; i < 6; i++)
        {
            int x = now.x + moveX[i];
            int y = now.y + moveY[i];
            int z = now.z + moveZ[i];
            if (correct(z,x,y) && matrix[z][x][y] == 0)
            {
                matrix[z][x][y] = matrix[now.z][now.x][now.y] + 1;
                queue.push(coords(z,x,y));
            }
        }
    }
    cout << steps - init;
}

int main()
{
    input();
    BFS();
    return 0;
}