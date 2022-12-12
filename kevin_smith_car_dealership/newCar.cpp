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

void newCar::loadCar()
{
    string newcarText;
    string newCarWords[7];
    fstream MyReadFile1("newCars.txt");
    int stringloop1 = 0;
    
    cout<<"New Cars"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    while (! MyReadFile1.eof()) {
        getline (MyReadFile1, newcarText);
        newCarWords[stringloop1] = newcarText;
        stringloop1 ++;
    }
    int size = sizeof(newCarWords)/sizeof(newCarWords[0]);
    for(int arrnum = 0; arrnum<size;arrnum++)
    {
        cout<<newCarWords[arrnum]<<endl;
    }
}

// function to add car to car list
void newCar::addCar()
{
    ofstream MyFile;
    MyFile.open("newCars.txt", ofstream::app);
    MyFile << getVin()<<" ";
    MyFile << getMake()<<" ";
    MyFile << getModel()<<" ";
    MyFile << getCategory()<<" ";
    MyFile << getPrice()<<" ";
    MyFile << getYear()<<" ";
    MyFile << getWarranty()<<" ";
    MyFile << "\n";
}


newCar::newCar()
{
    
}


newCar::newCar(string v, string ma, string mo, string c, float p, int y, string w):Car(v,ma,mo,c,p,y)
{
    setWarranty(w);
}

newCar::~newCar()
{
    
}
