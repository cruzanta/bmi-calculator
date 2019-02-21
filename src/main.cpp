#include <iostream>
#include <iomanip>

#include "../include/person.h"
#include "../include/bmi.h"

int main()
{
    double height, weight;
    int introBoxWid = 54;
    std::string appName = "Body Mass Index Calculator";
    std::string userResume;

    while (userResume != "n")
    {
        std::cout << "\n"
                  << std::string(introBoxWid, '*') << "\n"
                  << std::setw(1) << "*"
                  << std::setw((introBoxWid - appName.length() - 1) / 2) << ""
                  << std::setw(appName.length()) << appName
                  << std::setw((introBoxWid - appName.length() - 1) / 2) << ""
                  << std::setw(1) << "*" << "\n"
                  << std::string(introBoxWid, '*') << "\n"
                  << "\n";

        std::cout << "Your Height (inches): ";
        std::cin >> height;
        std::cout << "Your Weight (pounds): ";
        std::cin >> weight;

        Person user(height, weight);

        std::cout << "\n";
        displayBodyMassIndexReport(user.getHeight(), user.getWeight());
        std::cout << "\n" << "\n";

        std::cout << "Would you like to try a different height/weight? (y/n): ";
        std::cin >> userResume;

        while (userResume != "y" && userResume != "n")
        {
            std::cout << "Error: Please enter 'y' or 'n': ";
            std::cin >> userResume;
        }
    }

    return 0;
}
