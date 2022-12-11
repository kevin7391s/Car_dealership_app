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
 
    newCar* newCars[5];
    oldCar* oldCars[5];
    
        
    bool running = true;
    int newcounter = 0;
    int oldcounter = 0;
    int i = 0;
    int k = 0;
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
                newcounter ++;
                
                
                for(i=0; i<5; i++)
                {
                    newCars[i] = new newCar(vin,make,model,category,price,year,warranty);
                    //cout<<newCars[i]->getVin();
                    //newCars[i]->addCar();
                    i +=1;
                    cout<<i;
                    //newCars[i]->addCar();
                }
                
            }
            if(category == "old"){
                cout<<"Mileage = "<<endl;
                cin>>mileage;
                for(k=0; k<5; k++)
                {
                    oldCars[k] = new oldCar(vin,make,model,category,price,year,mileage);
                    //oldCars[k]->addCar();
                    k+=1;
                    //oldCars[k]->addCar();
                    //cout<<newCars[i]->getVin();
                    
                }
            }
            
    }
    
        if (user_input == 5){
            running = false;
        }
        
        
            
    
    //cout<<newCar1.getVin()<<newCar1.getMake()<<newCar1.getModel();
    }
    
    if(newcounter > 0){
        for(int b = 0; b < newcounter; b++){
            newCars[b]->addCar();
        }
    }
    if(oldcounter>0){
    for(int n = 0; n < oldcounter; n++){
        oldCars[n]->addCar();
        }
    }
    
    return 0;
}
