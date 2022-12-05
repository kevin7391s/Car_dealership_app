//
//  Car.hpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/4/22.
//

#ifndef Car_h
#define Car_h

#include <stdio.h>
#include <string>
using namespace std;


class Car
{
private:
    string vin;
    string make;
    string model;
    string category;
    float price;
    int year;

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
    
};

#endif /* Car_h */
