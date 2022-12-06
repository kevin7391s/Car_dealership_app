//
//  Car.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/4/22.
//

#include "Car.h"

void Car::setVin(string v)
{
    Vin = v;
}
void Car::setMake(string m)
{
    Make = m;
}
void Car::setModel(string m)
{
    Model = m;
}
void Car::setCategory(string c)
{
    Category = c;
}
void Car::setPrice(float p)
{
    Price = p;
}
void Car::setYear(int y)
{
    Year = y;
}



/* private:
    string vin;
    string make;
    string model;
    string category;
    float price;
    int year;
    int *list;
    Car *carlist;

public:
    // setters
    void setVin(string vin);
    void setMake(string make);
    void setModel(string model);
    void setCategory(string category);
    void setPrice(float price);
    void setYear(int year);
    
    // getters
    string getVin();
    string getMake();
    string getModel();
    string getCategory();
    float getPrice();
    int getYear();
    
    // constructors
    Car();
    Car(string vin, string make, string model, string category, float price, int year); */
    
