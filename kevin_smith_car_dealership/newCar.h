//
//  newCar.hpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/7/22.
//

#ifndef newCar_h
#define newCar_h
#include <stdio.h>
#include "Car.h"

class newCar : public Car
{
private:
    string warranty;
public:
    void setWarrant(string w);
    newCar(string v, string ma, string mo, string c, float p, int y, string w);
};
#endif /* newCar_h */
