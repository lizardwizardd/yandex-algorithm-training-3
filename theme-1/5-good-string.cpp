#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int numCount;
    long long inputInt;
    long long result;
    std::vector <long long> lettersNumber;
    std::cin >> numCount;

    while (numCount-- > 0)
    {
        std::cin >> inputInt;
        lettersNumber.push_back(inputInt);
    }

    for (int i = 1; i < (int)lettersNumber.size(); i++)
    {
        result += std::min(lettersNumber[i], lettersNumber[i-1]);
    }
    std::cout << result;
}