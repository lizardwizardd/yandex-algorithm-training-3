#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int k;
    string str;
    cin >> k >> str;

    int left = 0; 
    int beauty = 0;
    int max_beauty = 0;
    unordered_map<char, int> charFreq;

    for (int right = 0; right < str.size(); right++) 
    {
        charFreq[str[right]]++;
        beauty = max(beauty, charFreq[str[right]]);
        while (right - left + 1 - beauty > k)
        {
            charFreq[str[left]]--;
            left++;
        }
        max_beauty = max(max_beauty, right - left + 1);
    }

    cout << max_beauty << endl;

    return 0;
}
