#include <iostream>
#include <iomanip>

#include "../include/person.h"
#include "../include/bmi.h"

int main()
{
    // Declare variables for height and weight
    double height;
    double weight;
    // Initialize variables for the introduction box
    int introBoxWid = 54;
    std::string appName = "Body Mass Index Calculator";
    // Initialize variable for the control loop
    std::string userResume;

    while (userResume != "n")
    {
        // Display the introduction box with the application name
        std::cout << "\n"
                  << std::string(introBoxWid, '*') << "\n"
                  << std::setw(1) << "*"
                  << std::setw((introBoxWid - appName.length() - 1) / 2) << ""
                  << std::setw(appName.length()) << appName
                  << std::setw((introBoxWid - appName.length() - 1) / 2) << ""
                  << std::setw(1) << "*" << "\n"
                  << std::string(introBoxWid, '*') << "\n"
                  << "\n";

        // Prompt the user for their height and weight
        std::cout << "Your Height (inches): ";
        std::cin >> height;
        std::cout << "Your Weight (pounds): ";
        std::cin >> weight;

        // Initialize a Person object
        Person user(height, weight);

        // Display the BMI report
        std::cout << "\n";
        displayBodyMassIndexReport(user.getHeight(), user.getWeight());
        std::cout << "\n" << "\n";

        // Ask the user if they would like to continue
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
