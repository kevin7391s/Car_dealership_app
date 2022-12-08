//
//  main.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/4/22.
//

#include <iostream>
#include "Car.h"
using namespace std;

int main() {
    Car car1;
    
    
  
    cout<<car1.getYear()<<endl;
    car1.setYear(1999);
    cout<<car1.getYear()<<endl;

    
    return 0;
}
