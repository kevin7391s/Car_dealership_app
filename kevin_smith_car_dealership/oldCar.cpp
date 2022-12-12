//
//  oldCar.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/7/22.
//

#include "oldCar.h"

void oldCar::setMileage(int m)
{
    mileage = m;
}

int oldCar::getMileage()
{
    return mileage;
}

void oldCar::addCar()
{
    ofstream MyFile;
    MyFile.open("oldCar.txt", ofstream::app);
    MyFile << getVin()<<" ";
    MyFile << getMake()<<" ";
    MyFile << getModel()<<" ";
    MyFile << getCategory()<<" ";
    MyFile << getPrice()<<" ";
    MyFile << getYear()<<" ";
    MyFile << getMileage()<<" ";
    MyFile << ("\n");
    cout<<"Car added"<<endl;
    
}

void oldCar::loadCar(){
    string carText2;
    string oldCarWords[7];
    fstream MyReadFile("oldCar.txt");
    int stringloop = 0;
    
    cout<<"Old Cars"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    while (! MyReadFile.eof()) {
        getline (MyReadFile, carText2);
        oldCarWords[stringloop] = carText2;
        stringloop ++;
    }
    int size = sizeof(oldCarWords)/sizeof(oldCarWords[0]);
    for(int arrnum1 = 0; arrnum1<size;arrnum1++)
    {
        cout<<oldCarWords[arrnum1]<<endl;
    }
}


oldCar::oldCar()
{
    
}

oldCar::oldCar(string v, string ma, string mo, string c, float p, int y, int m):Car(v,ma,mo,c,p,y)
{
    setMileage(m);
}

oldCar::~oldCar()
{
    
}
