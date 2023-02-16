#include <iostream>
#include <fstream>

int main()
{
    std::fstream file;
    file.open("input.txt");

    int students, variants, desk, seat;
    file >> students >> variants >> desk >> seat;

    int studentNumber = (desk - 1) * 2 + seat;

    int numberBack, deskBack;
    int numberFront, deskFront;

    numberBack = studentNumber + variants;
    numberFront = studentNumber - variants;

    deskBack = (numberBack + 1) / 2;
    deskFront = (numberFront + 1) / 2;



    if (numberBack <= students && numberFront > 0)
    {
        //std::cout << "1st\n";
        if (deskBack - desk > desk - deskFront)
        {
            std::cout << deskFront << " " << 2 - numberFront % 2;
        }
        else 
        {
            std::cout << deskBack << " " << 2 - numberBack % 2;
        }
    }
    else if (numberBack <= students) 
    {
        //std::cout << "2nd\n";
        std::cout << deskBack << " " << 2 - numberBack % 2;
    }
    else if (numberFront > 0) 
    {
        //std::cout << "3rd\n";
        std::cout << deskFront << " " << 2 - numberFront % 2;
    }
    else 
    {
        std::cout << -1;
    }

    return 0;
}