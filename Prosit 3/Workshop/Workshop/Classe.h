#ifndef Classe_HEADER
#define Classe_HEADER

#include <ostream>
#include <string>

using namespace std;

namespace Exercice1
{
	class Car
	{
	private : 
		string license;
		string model;
		int year;

	public : 
		Car(string, string, int);
		string getLicence();
		int getYear();
		string toString();
	};

	class Accident
	{
	private :
		int reportNumber;
		string location;
		Car car1, car2;

	public :
		Accident();
		Accident(int, string, Car, Car);
		Car getFirstCar();
		Car getSecondCar();
		string toString();
	};
}

#endif // !Classe_HEADER
