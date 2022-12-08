//
//  oldCar.hpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/7/22.
//

#ifndef oldCar_h
#define oldCar_h
#include <stdio.h>
#include "Car.h"

class oldCar : public Car {
    
private:
    int mileage;

public:
    void setMileage(int m);
    int getMileage();
    
    oldCar(string v, string ma, string mo, string c, float p, int y, int m);
    ~oldCar();
    
};

#endif /* oldCar_h*/
