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
    cout<<"Car added"<<endl;
}

void newCar::searchCar(string ma, string mo, string wa)
{
    string carText3;
    string newCarWords3[7];
    string seperatedwords3[80];
    fstream MyReadFile1("newCars.txt");
    int stringloop3 = 0;
    
    while (! MyReadFile1.eof()) {
        getline (MyReadFile1, carText3);
        newCarWords3[stringloop3] = carText3;
        stringloop3 ++;
    }
    int size = sizeof(newCarWords3)/sizeof(newCarWords3[0]);
    
    for(int arrnum = 0; arrnum<size;arrnum++)
    {
        //cout<<newCarWords[arrnum]<<endl;
        istringstream ss(newCarWords3[arrnum]);
        string word;
        bool isMakeTrue = false;
        bool isModelTrue = false;
        int wordcounter3 = 0;
        while(ss >> word)
        {
            seperatedwords3[wordcounter3] = word;
            wordcounter3++;
            if(ma == seperatedwords3[wordcounter3])
            {
                //cout<<newCarWords3[arrnum]<<endl;
                isMakeTrue = true;
            }
            if(mo == seperatedwords3[wordcounter3])
            {
                isModelTrue = true;
            }
        }
        if(isMakeTrue && isModelTrue){
            cout<<newCarWords3[arrnum - 1]<<endl;
        }
        if(isMakeTrue != true || isModelTrue != true)
        {
            cout<<"-"<<endl;
        }
        
    }
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
