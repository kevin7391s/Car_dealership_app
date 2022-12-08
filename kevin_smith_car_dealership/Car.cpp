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

string Car::getVin()
{
    return Vin;
}

string Car::getMake()
{
    return Make;
}
string Car::getModel()
{
    return Model;
}
string Car::getCategory()
{
    return Category;
}
float Car::getPrice()
{
    return Price;
}
int Car::getYear()
{
    return Year;
}

// function to add car to car list
void Car::addCar()
{
    
}

// function to show cars
void Car::loadCar(){
   
   
}

Car::Car()
{
    Vin = "NA";
    Make = "NA";
    Model = "NA";
    Category = "NA";
    Price = 0.0;
    Year = 0;
}

Car::Car(string v, string ma, string mo, string c, float p, int y)
{
    setVin(v);
    setMake(ma);
    setModel(mo);
    setCategory(c);
    setPrice(p);
    setYear(y);
}

Car::~Car(){
    
}

    
