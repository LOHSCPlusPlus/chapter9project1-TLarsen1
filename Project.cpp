#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Car{
  enum {MAX_CHAR_LEN=100};
  char name[MAX_CHAR_LEN];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;
  char origin[MAX_CHAR_LEN];
  bool validentry;
  Car();
};

Car::Car(){
//name[MAX_CHAR_LEN] = "Unknown";
mpg = 0;
cylinders = 0;
displacement = 0;
horsepower = 0;
weight = 0;
acceleration = 0;
model = 0;
//origin[MAX_CHAR_LEN] = "Unknown";
validentry = false;
}

const int MAX_CARS = 500;
Car readCar(ifstream &inFile){
    Car car; 
    inFile.get(car.name, Car::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> car.mpg;
    inFile.ignore(100,';');
    inFile >> car.cylinders;
    inFile.ignore(100,';');
    inFile >> car.displacement;
    inFile.ignore(100,';');
    inFile >> car.horsepower;
    inFile.ignore(100,';');
    inFile >> car.weight;
    inFile.ignore(100,';');
    inFile >> car.acceleration;
    inFile.ignore(100,';');
    inFile >> car.model;
    inFile.ignore(100,';');
    inFile.get(car.origin, Car::MAX_CHAR_LEN);
    car.validentry = !inFile.eof();
    return car;
}

int readCars(Car Cars[]){
  ifstream CarFile("cars.txt");
  int numCars = 0;
  while(CarFile.peek() != EOF && numCars < MAX_CARS ){
  Cars[numCars] = readCar(CarFile);
  numCars++;
  }
  return numCars - 1;
}

int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

void printname(char name[]){
for(int index = 0; index < strlen(name); index++){
cout << name[index];
}
}


void printcars(Car carlist[], int numofcars){
for(int index = 0; index < numofcars; index++){
  if(carlist[index].validentry){
cout << "\n----------------------------" << endl;
printname(carlist[index].name); 
cout << " ";
cout << carlist[index].model;
cout << "\nMPG: " << (carlist[index].mpg);
cout << "\nCylinders: " << (carlist[index].cylinders);
cout << "\nDisplacement: " << (carlist[index].displacement);
cout << "\nHorsepower: " << (carlist[index].horsepower);
cout << "\nWeight: " << (carlist[index].weight);
cout << "\nAcceleration: " << (carlist[index].acceleration);
cout << "\nOrigin: "; 
printname(carlist[index].origin);
cout << "\nIndex: " << index;
  }
}
}

void lookupcar(Car carlist[], int numofcars, char origin[]){

for(int index = 0; index < numofcars; index++){
  if(!(strncmp(origin, carlist[index].origin, Car::MAX_CHAR_LEN))){
  if(carlist[index].validentry){
cout << "\n----------------------------" << endl;
printname(carlist[index].name); 
cout << " ";
cout << carlist[index].model;
cout << "\nMPG: " << (carlist[index].mpg);
cout << "\nCylinders: " << (carlist[index].cylinders);
cout << "\nDisplacement: " << (carlist[index].displacement);
cout << "\nHorsepower: " << (carlist[index].horsepower);
cout << "\nWeight: " << (carlist[index].weight);
cout << "\nAcceleration: " << (carlist[index].acceleration);
cout << "\nOrigin: "; 
printname(carlist[index].origin);
cout << "\nIndex: " << index;
  }
  }

}


}

void removecar(Car carlist[],int index){
carlist[index].validentry = false;
}

void addcar(Car carlist[],int &numcars){
Car car;
cin.ignore(100, '\n');
cout << "Enter car Name : ";
cin.get(car.name,Car::MAX_CHAR_LEN);
do{
cout << "Enter car Model : ";
cin >> car.model;
}while(car.model < 0);
do{
cout << "Enter car MPG : ";
cin >> car.mpg;
}while(car.mpg < 0);
do{
cout << "Enter car Cylinders : ";
cin >> car.cylinders;
}while(car.cylinders < 0);
do{
cout << "Enter car Displacement : ";
cin >> car.displacement;
}while(car.displacement < 0);
do{
cout << "Enter car Horsepower : ";
cin >> car.horsepower;
}while(car.horsepower < 0);
do{
cout << "Enter car Weight : ";
cin >> car.weight;
}while(car.weight < 0);
do{
cout << "Enter car Acceleration : ";
cin >> car.acceleration;
}while(car.acceleration < 0);
cout << "Enter car Origin : ";
cin.ignore(100,'\n');
cin.get(car.origin,Car::MAX_CHAR_LEN);
car.validentry = true;

carlist[numcars] = car;

numcars++;


}





int main(){
Car cars[MAX_CARS];
int num = readCars(cars);
int select = 0;
int selection = 0;
char origin[Car::MAX_CHAR_LEN];
do{
  cout << "Num of Cars : " << num << endl;
  int selection = readInt("\n1. Show Cars\n2. Remove a Car\n3. Add a Car\n4. Lookup Car by Origin\n5.Quit\n");
  if(selection == 1){
  printcars(cars, num);
  } 
  if(selection == 2){
    cout << "Etner a car's index to remove it : ";
    cin >> select;
    removecar(cars, select);
  }
  if(selection == 3){
    addcar(cars, num);
  }
  if(selection == 4){
    cout << "Enter Origin : ";
    cin.ignore(100, '\n');    
    cin.get(origin,Car::MAX_CHAR_LEN);
    lookupcar(cars, num, origin);
  }
  if(selection == 5){
    cout << "Exiting...";
    break;
  }
  else{
        cout << "\nInvalid";
  }

}while(selection != 5);

}