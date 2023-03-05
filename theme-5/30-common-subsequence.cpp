#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int n, m;
    std::cin >> n;
    std::vector<int> seqA (n);
    for (int i = 0; i != n; i++)
    {
        std::cin >> seqA[i];
    }

    std::cin >> m;
    std::vector<int> seqB (m);
    for (int i = 0; i != m; i++)
    {
        std::cin >> seqB[i];
    }

    std::vector<std::vector<int>> subSeqLen (n + 1, std::vector<int> (m + 1));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (seqA[i-1] == seqB[j-1])
            {
                subSeqLen[i][j] = subSeqLen[i-1][j-1] + 1;
            }
            else 
            {
                subSeqLen[i][j] = std::max(subSeqLen[i-1][j], subSeqLen[i][j-1]);
            }
        }
    }

    std::vector<int> maxSubSeq;
    int i = n, j = m;
    while (i > 0 && j > 0) 
    {
        if (seqA[i - 1] == seqB[j - 1]) 
        {
            maxSubSeq.push_back(seqA[i-1]);
            --i;
            --j;
        } 
        else if (subSeqLen[i-1][j] > subSeqLen[i][j-1]) 
        {
            --i;
        } 
        else 
        {
            --j;
        }
    }

    reverse(maxSubSeq.begin(), maxSubSeq.end());
    for (int x : maxSubSeq) 
    {
        std::cout << x << " ";
    }

    return 0;
}