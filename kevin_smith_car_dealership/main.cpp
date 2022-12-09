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
    
    bool running = true;
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
            string catergory;
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
            cin>>catergory;
            if(catergory == "new")
            {
                cout<<"Warranty = "<<endl;
                cin>>warranty;
            }
            else if(catergory == "old")
            {
                cout<<"Mileage = "<<endl;
                cin>>mileage;
            }
    
            
        }
    }
   
    
    
  
    
    
    return 0;
}
