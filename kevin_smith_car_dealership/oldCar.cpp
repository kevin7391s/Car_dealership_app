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
    string carText22;
    string oldCarWords22[7];
    fstream MyReadFile22("oldCar.txt");
    int stringloop22 = 0;
    
    cout<<"Old Cars"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    while (! MyReadFile22.eof()) {
        getline (MyReadFile22, carText22);
        oldCarWords22[stringloop22] = carText22;
        stringloop22 ++;
    }
    int size = sizeof(oldCarWords22)/sizeof(oldCarWords22[0]);
    for(int arrnum1 = 0; arrnum1<size;arrnum1++)
    {
        cout<<oldCarWords22[arrnum1]<<endl;
    }
    MyReadFile22.close();
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
    MyReadFile4.close();
}
void oldCar::sellLeaseCar(string ma,string mo, string cat)
{
        fstream MyoldReadFile5("oldCar.txt");
        ofstream MyFile5;
        
        ofstream MyFile6;
        MyFile6.open("leaselist1.txt",  ofstream::app);
        ofstream MyoldReopen;
        string newcarText6;
        string newCarWords6[7];
        string newCarWords7[7];
        string seperatedwords6[80];
        int stringloop6 = 0;
        
        while (! MyoldReadFile5.eof()) {
            getline (MyoldReadFile5, newcarText6);
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
        MyFile5.open("oldCar.txt");
        for(int arrnum7 = 0; arrnum7<size;arrnum7++)
        {
            //cout<<newCarWords7[arrnum7]<<endl;
            if(arrnum7 == 0){
                MyFile5 << " ";
                MyFile5.close();
                MyoldReopen.open("oldCar.txt", ofstream:: app);
            }

            MyoldReopen <<newCarWords7[arrnum7];
            MyoldReopen << "\n";
               
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
