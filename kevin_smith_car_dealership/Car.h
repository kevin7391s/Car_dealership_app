//
//  Car.hpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/4/22.
//

#ifndef Car_h
#define Car_h

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>


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
    //Car *carList;
    int count;
    

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
    
    // functionality
    void getCarInfo();
    void virtual addCar();
    void virtual loadCar();
    void virtual searchCar(string ma,string mo);
    void virtual sellLeaseCar(string ma, string mo, string cat);
    void returnLeasedCar(string ma, string mo);
    
    
    // constructors
    
    Car();
    Car(string ma,string mo);
    Car(string v, string ma, string mo, string c, float p, int y);
    
    ~Car();
    
};

#endif /* Car_h */
