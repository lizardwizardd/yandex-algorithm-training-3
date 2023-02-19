#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> a(N, vector<int>(M));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> prefixSums(N+1, vector<int>(M+1, 0));
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= M; j++) 
        {
            prefixSums[i][j] = a[i-1][j-1] + prefixSums[i-1][j] + prefixSums[i][j-1] - prefixSums[i-1][j-1];
        }
    }

    for (int q = 0; q < K; q++) 
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = prefixSums[x2][y2] - prefixSums[x2][y1-1] - prefixSums[x1-1][y2] + prefixSums[x1-1][y1-1];
        cout << result << endl;
    }

    return 0;
}
