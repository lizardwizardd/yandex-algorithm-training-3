#include <iostream>
#include <string>
#include <map>
#include <fstream>

int main()
{
    std::string word;
    std::map<char, long long> charCount;
    std::ifstream file;
    file.open("input.txt");
    std::getline(file, word);

    for (long long i = 1; i <= (long long)word.size(); i++)
    {
        charCount[word[i-1]] += i * ((long long)word.size() - i + 1);
    }

    for (auto [letter, count] : charCount)
    {
        std::cout << letter << ": " << count << '\n';
    }

    return 0;
}