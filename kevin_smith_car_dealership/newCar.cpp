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
    string newcarText10;
    string newCarWords10[7];
    fstream MyReadFile10("newCars.txt");
    int stringloop10 = 0;
    
    // used to print each line to show lists of cars
    cout<<"New Cars"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    while (! MyReadFile10.eof()) {
        getline (MyReadFile10, newcarText10);
        newCarWords10[stringloop10] = newcarText10;
        stringloop10 ++;
    }
    int size = sizeof(newCarWords10)/sizeof(newCarWords10[0]);
    for(int arrnum = 0; arrnum<size;arrnum++)
    {
        cout<<newCarWords10[arrnum]<<endl;
    }
    MyReadFile10.close();
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
    string carText33;
    string newCarWords33[7];
    string seperatedwords33[80];
    fstream MyReadFile33("newCars.txt");
    int stringloop33 = 0;
    
    while (! MyReadFile33.eof()) {
        getline (MyReadFile33, carText33);
        newCarWords33[stringloop33] = carText33;
        stringloop33 ++;
    }
    int size = sizeof(newCarWords33)/sizeof(newCarWords33[0]);
    
    for(int arrnum33 = 0; arrnum33<size;arrnum33++)
    {
        //cout<<newCarWords[arrnum]<<endl;
        istringstream ss(newCarWords33[arrnum33]);
        string word33;
        bool isMakeTrue33 = false;
        bool isModelTrue33 = false;
        bool isWarrantyTrue33 = false;
        int wordcounter33 = 0;
        while(ss >> word33)
        {
            seperatedwords33[wordcounter33] = word33;
            wordcounter33++;
            if(ma == seperatedwords33[wordcounter33])
            {
                //cout<<newCarWords3[arrnum]<<endl;
                isMakeTrue33 = true;
            }
            if(mo == seperatedwords33[wordcounter33])
            {
                isModelTrue33 = true;
            }
            if(wa == seperatedwords33[wordcounter33])
            {
                isWarrantyTrue33 = true;
            }
        }
        if(isMakeTrue33 && isModelTrue33 && isWarrantyTrue33){
            cout<<newCarWords33[arrnum33 - 1]<<endl;
        }
        if(isMakeTrue33 != true || isModelTrue33 != true || isWarrantyTrue33 != true)
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
    MyReadFile5.close();
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
