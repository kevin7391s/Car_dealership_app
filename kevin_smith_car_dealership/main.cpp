//
//  main.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/4/22.
//

#include <iostream>
#include "Car.h"
#include <fstream>
#include "newCar.h"
#include "oldCar.h"
using namespace std;

int main() {
    
    newCar newCar1;
    newCar newCar2;
    newCar newCar3;
    newCar newCar4;
    newCar newCar5;
    
    oldCar oldCar1;
    oldCar oldCar2;
    oldCar oldCar3;
    oldCar oldCar4;
    oldCar oldCar5;
    
    
    //newCar carList[] = new {newCar1, newCar2,newCar3,newCar4,newCar5};
    
    newCar* newCars[20];

    for(int i=0; i<20; i++)
    {
        newCars[i] = new newCar("NA",
                                "NA",
                                "NA",
                                "NA",
                                 0.0,
                                  0,
                                "NA");
        
        cout<<newCars[i]->getVin();
    }
    
    
  
    
    bool running = false;
    int i = 0;
    int user_input;
    while (running)
    {
        cout<<"1. Search Inventory"<<endl;
        cout<<"2. Sell/Lease cars"<<endl;
        cout<<"3. Return a leased car"<<endl;
        cout<<"4. Add cars to inventory"<<endl;
        cout<<"5. Exit"<<endl;
        cin >> user_input;
        
        if(user_input == 4)
        {
            string vin;
            string model;
            string make;
            string category;
            float price;
            int year;
            int mileage;
            string warranty;
            
            cout<<"Vin = "<<endl;
            cin>>vin;
            cout<<"Make = "<<endl;
            cin>>make;
            cout<<"Model = "<<endl;
            cin>>model;
            cout<<"Price = "<<endl;
            cin>>price;
            cout<<"Year = "<<endl;
            cin>>year;
            cout<<"Category = "<<endl;
            cin>>category;
            if(category == "new"){
                cout<<"Warranty = "<<endl;
                cin>>warranty;
                /*for(i = 0; i< sizeof(carList);i++)
                    //cout<<carList[i]<<endl;
                    carList[i].setVin(vin);
                    carList[i].setMake(make);
                    carList[i].setModel(model);
                    carList[i].setPrice(price);
                    carList[i].setYear(year);
                    carList[i].setCategory(category);
                    carList[i].setWarranty(warranty);
                break;
            }*/
        
            //cout<<"Mileage = "<<endl;
            //cin>>mileage;
         
            
        }
    }
    //cout<<newCar1.getVin()<<newCar1.getMake()<<newCar1.getModel();
    }
    
    return 0;
}
