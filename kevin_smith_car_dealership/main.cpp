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
 
    newCar* newCars[5];
    oldCar* oldCars[5];
    
    Car car1;
    newCar newCar1;
    newCar newCar2;
    oldCar oldCar1;
    oldCar oldCar2;
    
    
    bool running = true;
    int newcounter = 0;
    int oldcounter = 0;
    int i = 0;
    int k = 0;
    int user_input;
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
        
        if(user_input == 3)
        {
            //need to remove car from list
            string sellCarCategory;
            string sellmake;
            string sellmodel;
            bool ismaketrue = false;
            bool ismodeltrue = false;
            cout<<"Would you like to sell/lease a new car or an old car: ";
            cin>>sellCarCategory;
            cout<<"make of car: ";
            cin>>sellmake;
            cout<<"model of car: ";
            cin>>sellmodel;
            string carText5;
            string newCarWords5[7];
            string seperatedwords5[100];
            fstream MyReadFile5("newCars.txt");
            ofstream MyFile5;
            MyFile5.open("newCars.txt", ofstream::app);
            int stringloop5 = 0;
            
            while (! MyReadFile5.eof()) {
                getline (MyReadFile5, carText5);
                newCarWords5[stringloop5] = carText5;
                stringloop5 ++;
            }
            int size = sizeof(newCarWords5)/sizeof(newCarWords5[0]);
            
            for(int arrnum5 = 0; arrnum5<size;arrnum5++)
            {
                //cout<<newCarWords[arrnum]<<endl;
                istringstream ss(newCarWords5[arrnum5]);
                string word5;
                
                int wordcounter5 = 0;
                while(ss >> word5)
                {
                    seperatedwords5[wordcounter5] = word5;
                    
                    //cout<<seperatedwords5[wordcounter5];
                    if(sellmake == seperatedwords5[wordcounter5])
                    {
                        //cout<<newCarWords3[arrnum]<<endl;
                        ismaketrue = true;
                    }
                    if(sellmodel == seperatedwords5[wordcounter5])
                    {
                        ismodeltrue = true;
                    }
                    if(ismaketrue && ismodeltrue)
                    {
                        cout<<newCarWords5[arrnum5];
                        newCarWords5[arrnum5] = sellCarCategory;
                        MyFile5 <<newCarWords5[arrnum5];
                    }
                    wordcounter5++;
                }
               
            }
            MyReadFile5.close();
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
    
    // These 2 if statements used to add more than one car to file during loop
//    if(newcounter > 0){
//        for(int b = 0; b <= 1; b++){
//            newCars[b]->addCar();
//            delete newCars[b];
//        }
//    }
//    if(oldcounter>0){
//    for(int n = 0; n <= 1; n++){
//        oldCars[n]->addCar();
//        delete oldCars[n];
//        }
//    }
    
    
    return 0;
}
