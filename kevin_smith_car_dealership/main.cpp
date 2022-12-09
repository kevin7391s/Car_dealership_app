//
//  main.cpp
//  kevin_smith_car_dealership
//
//  Created by Kevin Smith on 12/4/22.
//

#include <iostream>
#include "Car.h"
#include <fstream>
using namespace std;

int main() {
    Car car1;
    
    ofstream MyFile;
    MyFile.open("File.txt");
    

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!\n";

    // Close the file
    MyFile.close();
  
    cout<<car1.getYear()<<endl;
    car1.setYear(1999);
    MyFile <<car1.getYear();
    
    
    //MyFile <<"Hellowordl";
  
    
    
    return 0;
}
