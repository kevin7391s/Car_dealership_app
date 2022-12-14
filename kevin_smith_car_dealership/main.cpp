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
#include <sstream>


using namespace std;

int main() {
 
    // create newCar and oldCar array to that will be used to store data in file
    newCar* newCars[5];
    oldCar* oldCars[5];
    
    // create objects used to call functions
    Car car1;
    Car car2;
    newCar newCar1;
    newCar newCar2;
    oldCar oldCar1;
    oldCar oldCar2;
    
    // variables used in main
    bool running = true;
    int newcounter = 0;
    int oldcounter = 0;
    int i = 0;
    int k = 0;
    int user_input;
    
    // while loop that continously runs until user_input == 6
    while (running)
    {
        
        // main menu
        cout<<"1. Load Cars"<<endl;
        cout<<"2. Search Inventory"<<endl;
        cout<<"3. Sell/Lease cars"<<endl;
        cout<<"4. Return a leased car"<<endl;
        cout<<"5. Add cars to inventory"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter input: ";
        cin >> user_input;
        
        // function used to load cars
        if(user_input == 1)
        {
            
            newCar1.loadCar();
            oldCar1.loadCar();
            
        }
        if(user_input == 2){
            string categoryinput;
            string newmake;
            string newmodel;
            cout<<"Enter the category you would like to search for (new or old)";
            cin>>categoryinput;
            cout<<"Enter make: ";
            cin>>newmake;
            cout<<"Enter model: ";
            cin>>newmodel;
            
            if(categoryinput == "new")
            {
                string newwarranty;
                cout<<"Enter warranty: ";
                cin>>newwarranty;
                newCar2.searchCar(newmake, newmodel, newwarranty);
            }
            if(categoryinput == "old")
            {
                string newmileage;
                cout<<"Enter mileage: ";
                cin>>newmileage;
                oldCar2.searchCar(newmake, newmodel, newmileage);
            }
        }
        // sell/lease car. Removes from car list if sold and adds to lease list if leased
        if(user_input == 3)
        {
            //need to remove car from list
            string sellCarCategory;
            string sellmake;
            string sellmodel;
            string oldornew;
          
            cout<<"Would you like to sell/lease: ";
            cin>>sellCarCategory;
            cout<<"New car or old car?: ";
            cin>>oldornew;
            cout<<"Make of car: ";
            cin>>sellmake;
            cout<<"Model of car: ";
            cin>>sellmodel;
            
            if(oldornew == "new"){
                newCar1.sellLeaseCar(sellmake, sellmodel, sellCarCategory);
            }
            if(oldornew == "old"){
                oldCar1.sellLeaseCar(sellmake, sellmodel, sellCarCategory);
            }
        }
        
        // return leased car
        if(user_input == 4)
        {
            string makereturnedcar;
            string modelreturnedcar;
            cout<<"make of car being returned: ";
            cin>>makereturnedcar;
            cout<<"model of car being returned: ";
            cin>>modelreturnedcar;
            
            car2.returnLeasedCar(makereturnedcar, modelreturnedcar);
        }
        
        // add cars to file
        if(user_input == 5)
        {
            
            // create variables and add new or old car depending on user input
            string vin;
            string model;
            string make;
            string category;
            float price;
            int year;
            int mileage;
            string warranty;
            
            cout<<"Vin = ";
            cin>>vin;
            cout<<"Make = ";
            cin>>make;
            cout<<"Model = ";
            cin>>model;
            cout<<"Price = ";
            cin>>price;
            cout<<"Year = ";
            cin>>year;
            cout<<"Category = ";
            cin>>category;
        
            // accept warranty and add car to newcar file
            if(category == "new"){
                cout<<"Warranty = ";
                cin>>warranty;
                newcounter ++;
                for(i=0; i<1; i++)
                {
                    newCars[i] = new newCar(vin,make,model,category,price,year,warranty);
                    newCars[i]->addCar();
                    delete newCars[i];
                }
            }
            
            // accept mileage and accept and add to oldcar file
            if(category == "old"){
                cout<<"Mileage = ";
                cin>>mileage;
                oldcounter ++;
                for(k=0; k<1; k++)
                {
                    oldCars[k] = new oldCar(vin,make,model,category,price,year,mileage);
                    oldCars[k]->addCar();
                    delete oldCars[k];
                    
                }
            }
            
        }
    
        // break loop and end program
        if (user_input == 6){
            running = false;
        }
        
        
    }
    

    return 0;
}
