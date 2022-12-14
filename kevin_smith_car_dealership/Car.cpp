//
//  Car.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/4/22.
//

#include "Car.h"

// setters
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

//getters
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
    
    MyFile.close();
    
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
    // variables for storing data in lists
    string carText3;
    string newCarWords3[7];
    string seperatedwords3[80];
    fstream MyReadFile1("File.txt");
    int stringloop3 = 0;
    // used to read each line of file and store in an array
    while (! MyReadFile1.eof()) {
        getline (MyReadFile1, carText3);
        newCarWords3[stringloop3] = carText3;
        stringloop3 ++;
    }
    int size = sizeof(newCarWords3)/sizeof(newCarWords3[0]);
    
    // used to seperate spaces from string and store in a new list of seperate words
    for(int arrnum = 0; arrnum<size;arrnum++)
    {
        
        istringstream ss(newCarWords3[arrnum]);
        string word;
        // if user input == word in line of that file, print that line to show search results
        bool isMakeTrue = false;
        bool isModelTrue = false;
        int wordcounter3 = 0;
        while(ss >> word)
        {
            seperatedwords3[wordcounter3] = word;
            wordcounter3++;
            if(ma == seperatedwords3[wordcounter3])
            {
              
                isMakeTrue = true;
            }
            if(mo == seperatedwords3[wordcounter3])
            {
                isModelTrue = true;
            }
        }
        // print line of true statment
        if(isMakeTrue && isModelTrue){
            cout<<newCarWords3[arrnum - 1]<<endl;
        }
        // print - if car make/model is not equal to words in that line
        if(isMakeTrue != true || isModelTrue != true)
        {
            cout<<"-"<<endl;
        }
        
    }
}

void Car::sellLeaseCar(string ma, string mo, string cat){
    
    // read cars file and open lease list file
    fstream MyReadFile5("newFile.txt");
    ofstream MyFile5;
    
    ofstream MyFile6;
    MyFile6.open("leaselist1.txt",  ofstream::app);
    
    // create a reopen file to reopen file after clearing it to rewrite to it later in function
    ofstream MyReopen;
    string newcarText6;
    string newCarWords6[7];
    string newCarWords7[7];
    string seperatedwords6[80];
    int stringloop6 = 0;
    
    // store data in arrays also copy array in to another array which is used later to write to file
    while (! MyReadFile5.eof()) {
        getline (MyReadFile5, newcarText6);
        newCarWords6[stringloop6] = newcarText6;
        newCarWords7[stringloop6] = newCarWords6[stringloop6];
        stringloop6 ++;
    }
    int size = sizeof(newCarWords6)/sizeof(newCarWords6[0]);
    for(int arrnum6 = 0; arrnum6<size;arrnum6++)
    {
        // find words in each line
        istringstream ss(newCarWords6[arrnum6]);
        string word6;
        bool maketrue= false;
        bool modtrue = false;
        int wordcounter6 = 0;
        while(ss >> word6)
            
        {
            seperatedwords6[wordcounter6] = word6;
            wordcounter6++;
            if(ma == seperatedwords6[wordcounter6]){
                maketrue = true;
            }
            if(mo == seperatedwords6[wordcounter6]){
                modtrue = true;
            }
            // if category == lease store it in the lease file
            if(maketrue && modtrue){
                if(cat == "lease"){
                    MyFile6 << newCarWords7[arrnum6 - 1];
                    MyFile6.close();
                }
                // store lease or sell in that category instead of the data
                newCarWords7[arrnum6 -1] = cat;
            }
    }
        
    }
    MyFile5.open("newCars.txt");
    for(int arrnum7 = 0; arrnum7<size;arrnum7++)
    {
        // this is used to clear data out of the file so we can rewrite to it
        if(arrnum7 == 0){
            MyFile5 << " ";
            MyFile5.close();
            MyReopen.open("newCars.txt", ofstream:: app);
        }

        // rewrite the new array to the file with the updated list that contains lease or sell
        MyReopen <<newCarWords7[arrnum7];
        MyReopen << "\n";
           
    }
}

void Car::returnLeasedCar(string ma, string mo)
{
    // same idea as above function
    // read file and store to oldCar.txt from leaselist1.txt
    fstream MyoldReadFile6("leaselist1.txt");
    ofstream MyFile8;
    
    ofstream MyFile9;
    MyFile9.open("oldCar.txt",  ofstream::app);
    ofstream MyleaseReopen;
    string newcarText9;
    string newCarWords8[7];
    string newCarWords9[7];
    string seperatedwords9[80];
    int stringloop9 = 0;
    
    // store lines of data in array and copy array
    while (! MyoldReadFile6.eof()) {
        getline (MyoldReadFile6, newcarText9);
        newCarWords8[stringloop9] = newcarText9;
        newCarWords9[stringloop9] = newCarWords8[stringloop9];
        stringloop9 ++;
    }
    int size9 = sizeof(newCarWords9)/sizeof(newCarWords9[0]);
    for(int arrnum9 = 0; arrnum9<size9;arrnum9++)
    {
        cout<<newCarWords8[arrnum9]<<endl;
        istringstream ss(newCarWords8[arrnum9]);
        string word9;
        bool maketrue9= false;
        bool modtrue9 = false;
        int wordcounter9 = 0;
        while(ss >> word9)
            
        {
            // if user input == word then set to true
            seperatedwords9[wordcounter9] = word9;
            cout<<seperatedwords9[wordcounter9]<<endl;
            wordcounter9++;
            
            if(ma == seperatedwords9[wordcounter9]){
                maketrue9 = true;
            }
            if(mo == seperatedwords9[wordcounter9]){
                modtrue9 = true;
            }
            if(maketrue9 && modtrue9){
                
                // store data in oldCar.txt
                MyFile9 << newCarWords9[arrnum9 - 1];
                MyFile9 << "\n";
                MyFile9.close();
                newCarWords9[arrnum9 -1] = "returned";
                
            }
    }
        // rewrite leaselist.txt
    }
    MyFile8.open("leaselist1.txt");
    for(int arrnum8 = 0; arrnum8<size9;arrnum8++)
    {
        //cout<<newCarWords7[arrnum7]<<endl;
        if(arrnum8 == 0){
            MyFile8 << " ";
            MyFile8.close();
            MyleaseReopen.open("leaselist1.txt", ofstream:: app);
        }

        MyleaseReopen <<newCarWords9[arrnum8];
        MyleaseReopen << "\n";
           
    }
    // close file
    MyleaseReopen.close();
    MyoldReadFile6.close();

}


// constructors
Car::Car()
{

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

    
