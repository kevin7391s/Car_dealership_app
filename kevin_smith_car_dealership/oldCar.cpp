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

void oldCar::searchCar(string ma, string mo, string mi)
{
    string carText4;
    string newCarWords4[7];
    string seperatedwords4[80];
    fstream MyReadFile4("oldCar.txt");
    int stringloop4 = 0;
    
    while (! MyReadFile4.eof()) {
        getline (MyReadFile4, carText4);
        newCarWords4[stringloop4] = carText4;
        stringloop4 ++;
    }
    int size = sizeof(newCarWords4)/sizeof(newCarWords4[0]);
    
    for(int arrnum = 0; arrnum<size;arrnum++)
    {
        //cout<<newCarWords[arrnum]<<endl;
        istringstream ss(newCarWords4[arrnum]);
        string word;
        bool isMakeTrue1 = false;
        bool isModelTrue1 = false;
        bool isMileageTrue1 = false;
        int wordcounter4 = 0;
        while(ss >> word)
        {
            seperatedwords4[wordcounter4] = word;
            wordcounter4++;
            if(ma == seperatedwords4[wordcounter4])
            {
                //cout<<newCarWords3[arrnum]<<endl;
                isMakeTrue1 = true;
            }
            if(mo == seperatedwords4[wordcounter4])
            {
                isModelTrue1 = true;
            }
            if(mi == seperatedwords4[wordcounter4])
            {
                isMileageTrue1 = true;
            }
        }
        if(isMakeTrue1 && isModelTrue1 && isMileageTrue1){
            cout<<newCarWords4[arrnum - 1]<<endl;
        }
        if(isMakeTrue1 != true || isModelTrue1 != true || isMileageTrue1 != true)
        {
            cout<<"-"<<endl;
        }
        
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
