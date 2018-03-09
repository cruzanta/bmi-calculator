#ifndef BMI_H
#define BMI_H

// Function prototypes
double calculateBMI(double height, double weight);
double calculateLowNormalWeight(double height);
double calculateHighNormalWeight(double height);
std::string assignWeightCategory(double height, double weight);
std::string roundedDoubleStr(double num);
void displayBodyMassIndexReport(double height, double weight);

#endif
