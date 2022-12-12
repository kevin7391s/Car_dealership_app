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
    string newcarText;
    string newCarWords[7];
    string seperatedwords[80];
    fstream MyReadFile1("File.txt");
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
        bool isSearchTrue = false;
        int wordcounter = 0;
        while(ss >> word)
        {
            seperatedwords[wordcounter] = word;
            wordcounter++;
            if(ma == seperatedwords[wordcounter] && mo == seperatedwords[wordcounter])
            {
                cout<<newCarWords[arrnum]<<endl;
                isSearchTrue = true;
            }
        }
        if(isSearchTrue != true)
        {
            cout<<"No search found"<<endl;
        }
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

    
