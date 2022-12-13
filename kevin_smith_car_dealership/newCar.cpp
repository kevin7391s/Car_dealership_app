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
        bool isWarrantyTrue = false;
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
            if(wa == seperatedwords3[wordcounter3])
            {
                isWarrantyTrue = true;
            }
        }
        if(isMakeTrue && isModelTrue && isWarrantyTrue){
            cout<<newCarWords3[arrnum - 1]<<endl;
        }
        if(isMakeTrue != true || isModelTrue != true || isWarrantyTrue != true)
        {
            cout<<"-"<<endl;
        }
        
    }
}

void newCar::sellLeaseCar(string ma, string mo, string cat){
    fstream MyReadFile5("newCars.txt");
    ofstream MyFile5;
    
    ofstream MyFile6;
    MyFile6.open("leaselist1.txt",  ofstream::app);
    ofstream MyReopen;
    string newcarText6;
    string newCarWords6[7];
    string newCarWords7[7];
    string seperatedwords6[80];
    int stringloop6 = 0;
    
    while (! MyReadFile5.eof()) {
        getline (MyReadFile5, newcarText6);
        newCarWords6[stringloop6] = newcarText6;
        newCarWords7[stringloop6] = newCarWords6[stringloop6];
        stringloop6 ++;
    }
    int size = sizeof(newCarWords6)/sizeof(newCarWords6[0]);
    for(int arrnum6 = 0; arrnum6<size;arrnum6++)
    {
       
        istringstream ss(newCarWords6[arrnum6]);
        string word6;
        bool maketrue= false;
        bool modtrue = false;
        int wordcounter6 = 0;
        while(ss >> word6)
            
        {
            seperatedwords6[wordcounter6] = word6;
            wordcounter6++;
            //cout<<seperatedwords6[wordcounter6]<<endl;
            if(ma == seperatedwords6[wordcounter6]){
                maketrue = true;
            }
            if(mo == seperatedwords6[wordcounter6]){
                modtrue = true;
            }
            if(maketrue && modtrue){
                if(cat == "lease"){
                    MyFile6 << newCarWords7[arrnum6 - 1];
                    MyFile6 << "\n";
                    MyFile6.close();
                }
                newCarWords7[arrnum6 -1] = cat;
            }
    }
        
    }
    MyFile5.open("newCars.txt");
    for(int arrnum7 = 0; arrnum7<size;arrnum7++)
    {
        //cout<<newCarWords7[arrnum7]<<endl;
        if(arrnum7 == 0){
            MyFile5 << " ";
            MyFile5.close();
            MyReopen.open("newCars.txt", ofstream:: app);
        }

        MyReopen <<newCarWords7[arrnum7];
        MyReopen << "\n";
           
    }
    MyReopen.close();
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
