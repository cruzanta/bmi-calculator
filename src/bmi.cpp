#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "../include/bmi.h"

double calculateBMI(double height, double weight)
{
    return (weight / std::pow(height, 2)) * 703;
}

double calculateLowNormalWeight(double height)
{
    return (18.5 / 703) * std::pow(height, 2);
}

double calculateHighNormalWeight(double height)
{
    return (24.9 / 703) * std::pow(height, 2);
}

std::string assignWeightCategory(double height, double weight)
{
    std::string category;
    double bmi = calculateBMI(height, weight);

    if (bmi >= 30)
        category = "Obesity";
    else if (bmi >= 25)
        category = "Overweight";
    else if (bmi >= 18.5)
        category = "Normal";
    else
        category = "Underweight";

    return category;
}

std::string roundedDoubleStr(double num)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << num;

    return stream.str();
}

void displayBodyMassIndexReport(double height, double weight)
{
    // Initialize an integer variable to hold the width of the entire table
    int tableWid = 0;
    // Initialize an array to hold the widths of each non-header row's columns
    long unsigned int colWids[] = {1, 25, 2, 25, 1};
    // Initialize the strings to be displayed in the table
    std::string headerRowStr = "Body Mass Index (BMI) Report";
    std::string bmi = roundedDoubleStr(calculateBMI(height, weight));
    std::string category = assignWeightCategory(height, weight);
    std::string lowWeight = roundedDoubleStr(calculateLowNormalWeight(height)) + " lbs.";
    std::string highWeight = roundedDoubleStr(calculateHighNormalWeight(height)) + " lbs.";
    // Define a structure for each row of the table
    struct Row
    {
        std::string leftColStr;
        std::string midColStr;
        std::string rightColStr;
        long unsigned int borderColWid;
        long unsigned int leftColWid;
        long unsigned int midColWid;
        long unsigned int rightColWid;
    };

    // Calculate the width of the entire table
    for (int i = 0; i < sizeof(colWids) / sizeof(colWids[0]); i++)
    {
        tableWid += colWids[i];
    }

    // Initialize an array of row structures
    Row tableRows[] =
    {
        {
            "",
            headerRowStr,
            "",
            colWids[0],
            (tableWid - colWids[0] - headerRowStr.length()) / 2,
            headerRowStr.length(),
            (tableWid - colWids[0] - headerRowStr.length()) / 2
        },

        {
            "BMI",
            ":",
            bmi,
            colWids[0],
            colWids[1],
            colWids[2],
            colWids[3]
        },

        {
            "Weight Category",
            ":",
            category,
            colWids[0],
            colWids[1],
            colWids[2],
            colWids[3]
        },

        {
            "Low Normal Weight",
            ":",
            lowWeight,
            colWids[0],
            colWids[1],
            colWids[2],
            colWids[3]
        },

        {
            "High Normal Weight",
            ":",
            highWeight,
            colWids[0],
            colWids[1],
            colWids[2],
            colWids[3]
        }
    };

    // Loop through the array of row structures for table output
    for (int i = 0; i < sizeof(tableRows) / sizeof(tableRows[0]); i++)
    {
        std::cout << std::left
                << std::string(tableWid, '-') << "\n"
                << std::setw(tableRows[i].borderColWid) << "|"
                << std::setw(tableRows[i].leftColWid) << tableRows[i].leftColStr
                << std::setw(tableRows[i].midColWid) << tableRows[i].midColStr
                << std::setw(tableRows[i].rightColWid) << tableRows[i].rightColStr
                << std::setw(tableRows[i].borderColWid) << "|" << "\n";

        if (i == sizeof(tableRows) / sizeof(tableRows[0]) - 1)
            std::cout << std::string(tableWid, '-');
    }
}
