//
//  Car.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/4/22.
//

#include "Car.h"


void Car::setVin(string v)
{
    Vin = v;
}
void Car::setMake(string m)
{
    Make = m;
}
void Car::setModel(string m)
{
    Model = m;
}
void Car::setCategory(string c)
{
    Category = c;
}
void Car::setPrice(float p)
{
    Price = p;
}
void Car::setYear(int y)
{
    Year = y;
}

string Car::getVin()
{
    return Vin;
}

string Car::getMake()
{
    return Make;
}
string Car::getModel()
{
    return Model;
}
string Car::getCategory()
{
    return Category;
}
float Car::getPrice()
{
    return Price;
}
int Car::getYear()
{
    return Year;
}


// function to add car to car list
void Car::addCar()
{
    ofstream MyFile;
    MyFile.open("File.txt", ofstream::app);
    MyFile << getVin();
    MyFile << getMake();
    MyFile << getModel();
    MyFile << getCategory();
    MyFile << getPrice();
    MyFile << getYear();
    
}

// function to show cars
void Car::loadCar(){
    string carText;
    fstream MyReadFile("File.txt");
    
    while (getline (MyReadFile, carText)) {
      // Output the text from the file
      cout << carText;
    }
}
void Car::searchCar(string ma, string mo)
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

void Car::sellLeaseCar(string ma, string mo, string cat){
    fstream MyReadFile5("newFile.txt");
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
        //newCarWords[arrnum] = "null";
        //cout<<newCarWords6[arrnum6]<<endl;
        //cout<<newCarWords7[arrnum6]<<endl;
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
}

Car::Car()
{
    Vin = "NA";
    Make = "NA";
    Model = "NA";
    Category = "NA";
    Price = 0.0;
    Year = 0;
}

Car::Car(string ma, string mo)
{
    ma = "null";
    mo = "null";
}

Car::Car(string v, string ma, string mo, string c, float p, int y)
{
    setVin(v);
    setMake(ma);
    setModel(mo);
    setCategory(c);
    setPrice(p);
    setYear(y);
}

Car::~Car(){
    
}

    
