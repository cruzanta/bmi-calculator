#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person(double height, double weight);

    double getHeight();
    double getWeight();

    void setHeight(double height);
    void setWeight(double weight);

private:
    double height, weight;
};

#endif
