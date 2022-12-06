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
    string Vin;
    string Make;
    string Model;
    string Category;
    float Price;
    int Year;
    int *List;
    Car *carList;

public:
    // setters
    void setVin(string v);
    void setMake(string m);
    void setModel(string m);
    void setCategory(string c);
    void setPrice(float p);
    void setYear(int y);
    
    // getters
    string getVin();
    string getMake();
    string getModel();
    string getCategory();
    float getPrice();
    int getYear();
    
    // constructors
    Car();
    Car(string Vin, string Make, string Model, string Category, float Price, int Year);
    
};

#endif /* Car_h */
