#include "Classe.h"
#include <string>

using namespace std;
Exercice1::Car::Car(string License, string Model, int Year)
{
	license = License;
	model = Model;
	year = Year;
}

string Exercice1::Car::getLicence()
{
	return license;
}

int Exercice1::Car::getYear()
{
	return year;
}

string Exercice1::Car::toString()
{
	string txt;
	txt += license;
	txt += " ";
	txt += to_string(year);
	txt += " ";
	txt += model;
	return txt;
}

Exercice1::Accident::Accident()
{
	reportNumber = 0;
	location = "XXX";
	car1 = car2 = NULL;
}

Exercice1::Accident::Accident(int Number, string Location, Car Car1, Car Car2)
{
	reportNumber = Number;
	location = Location;
	car1 = Car1;
	car2 = Car2;
}

Exercice1::Car& Exercice1::Accident::getFirstCar()
{
	return car1;
}

Exercice1::Car& Exercice1::Accident::getSecondCar()
{
	return car2;
}

string& Exercice1::Accident::toString()
{
	return ("car 1 : " + car1.license + "\n" +  car1.model + "\n" + (string)car1.getYear + "car 1 : " + car2.license + "\n" + car2.model + "\n" + (string)car2.getYear);
}