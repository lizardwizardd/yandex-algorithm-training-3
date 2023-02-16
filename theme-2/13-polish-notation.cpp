#include <cctype>
#include <ctype.h>
#include <iostream>
#include <string>
#include <stack>

int int_to_char(int digit)
{
    return char(digit + 48);
}

int char_to_int(int symbol)
{
    return (int)symbol - 48;
}

int main()
{
    std::stack<int> stack;

    char input;
    int operationResult;
    int deletedDigit;
    while (std::cin >> input)
    {
        if (isdigit(input))
        {
            stack.push(char_to_int(input));
        }
        else 
        {
            deletedDigit = stack.top();
            stack.pop();

            if (input == '-')
            {
                operationResult = stack.top() - deletedDigit;
                stack.pop();
                stack.push(operationResult);
            }
            else if (input == '+') 
            {
                operationResult = stack.top() + deletedDigit;
                stack.pop();
                stack.push(operationResult);
            }
            else if (input == '*') 
            {
                operationResult = stack.top() * deletedDigit; 
                stack.pop();
                stack.push(operationResult);
            }
        }
    }

    std::cout << stack.top();

    return 0;
}