//
//  newCar.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/7/22.
//

#include "newCar.h"

void newCar::setWarranty(string w)
{
    warranty = w;
}

string newCar::getWarranty()
{
    return warranty;
}

newCar::newCar(string v, string ma, string mo, string c, float p, int y, string w):Car(v,ma,mo,c,p,y)
{
    setWarranty(w);
}

newCar::~newCar()
{
    
}
