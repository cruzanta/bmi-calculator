#include "../include/person.h"

Person::Person(double height, double weight)
{
    setHeight(height);
    setWeight(weight);
}

double Person::getHeight()
{
    return height;
}

double Person::getWeight()
{
    return weight;
}

void Person::setHeight(double height)
{
    this->height = height;
}

void Person::setWeight(double weight)
{
    this->weight = weight;
}
