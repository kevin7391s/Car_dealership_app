//
//  oldCar.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/7/22.
//

#include "oldCar.h"

void oldCar::setMileage(int m)
{
    mileage = m;
}

int oldCar::getMileage()
{
    return mileage;
}

void oldCar::addCar()
{
    ofstream MyFile;
    MyFile.open("oldCar.txt");
    MyFile << getVin();
    MyFile << getMake();
    MyFile << getModel();
    MyFile << getCategory();
    MyFile << getPrice();
    MyFile << getYear();
    
}



oldCar::oldCar()
{
    
}

oldCar::oldCar(string v, string ma, string mo, string c, float p, int y, int m):Car(v,ma,mo,c,p,y)
{
    setMileage(m);
}

oldCar::~oldCar()
{
    
}
