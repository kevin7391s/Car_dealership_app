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
    // setter & getter
    void setWarranty(string w);
    string getWarranty();
    
    // inherited function
    void addCar();
    void loadCar();
    void searchCar(string ma, string mo, string wa);
    // function to overide
    void sellLeaseCar(string ma, string mo, string cat);
    
    // constructor and destructor
    newCar();
    newCar(string v, string ma, string mo, string c, float p, int y, string w);
    ~newCar();
};
#endif /* newCar_h */
