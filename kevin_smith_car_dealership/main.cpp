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
    
    newCar newCar1;
    oldCar oldCar1;
    
        
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
            //cout<<"Enter the category you would like to search for (new or old)";
            //cin>>categoryinput;
            string newsearchCat;
            string newsearch;
            cout<<"Would you like to search by make, model, or warranty: ";
            cin>>newsearchCat;
            cout<<"Enter the "<<newsearchCat<<": ";
            cin>>newsearch;
            string newcarText;
            string newCarWords[7];
            string seperatedwords[80];
            fstream MyReadFile1("newCars.txt");
            int stringloop1 = 0;
            
            while (! MyReadFile1.eof()) {
                getline (MyReadFile1, newcarText);
                newCarWords[stringloop1] = newcarText;
                stringloop1 ++;
            }
            int size = sizeof(newCarWords)/sizeof(newCarWords[0]);
            
            for(int arrnum = 0; arrnum<size;arrnum++)
            {
                //cout<<newCarWords[arrnum]<<endl;
                istringstream ss(newCarWords[arrnum]);
                string word;
                int wordcounter = 0;
                while(ss >> word)
                {
                    seperatedwords[wordcounter] = word;
                    wordcounter++;
                    if(newsearch == seperatedwords[wordcounter])
                    {
                        cout<<newCarWords[arrnum]<<endl;
                    }
                }
            }
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
                for(i=0; i<5; i++)
                {
                    newCars[i] = new newCar(vin,make,model,category,price,year,warranty);
                }
            }
            
            // accept mileage and accept and add to oldcar file
            if(category == "old"){
                cout<<"Mileage = ";
                cin>>mileage;
                oldcounter ++;
                for(k=0; k<5; k++)
                {
                    oldCars[k] = new oldCar(vin,make,model,category,price,year,mileage);
                }
            }
            
        }
    
        // break loop and end program
        if (user_input == 6){
            running = false;
        }
        
        
    }
    
    // These 2 if statements used to add more than one car to file during loop
    if(newcounter > 0){
        for(int b = 0; b <= newcounter; b++){
            newCars[b]->addCar();
            delete newCars[b];
        }
    }
    if(oldcounter>0){
    for(int n = 0; n <= oldcounter; n++){
        oldCars[n]->addCar();
        delete oldCars[n];
        }
    }
    
    
    return 0;
}
