#include <ostream>
#include <string>
#include "Matrice.h"

using namespace std;

Matrice::Matrice()
{
	tailleX = 5;
	tailleY = 5;

	datalist = new int* [tailleX];

	for (int i = 0; i < tailleY; i++)
		datalist[i] = new int[tailleY];

	for (int xCoordinate = 0; xCoordinate < tailleX; xCoordinate++)
		for (int yCoordinate = 0; yCoordinate < tailleY; yCoordinate++)
			datalist[xCoordinate][yCoordinate] = 0;
}

Matrice::Matrice(int newTailleX, int newTailleY)
{
	tailleX = newTailleX;
	tailleY = newTailleY;

	datalist = new int*[tailleX];

	for (int i = 0; i < tailleY; i++)
		datalist[i] = new int[tailleY];

	for (int xCoordinate = 0; xCoordinate < tailleX; xCoordinate++)
		for (int yCoordinate = 0; yCoordinate < tailleY; yCoordinate++)
			datalist[xCoordinate][yCoordinate] = 0;
}

void Matrice::setPoint(int xCo, int yCo)
{
	x = xCo;
	y = yCo;

	for (int xCoordinate = 0; xCoordinate < tailleX; xCoordinate++)
		for (int yCoordinate = 0; yCoordinate < tailleY; yCoordinate++)
		{
			if (xCoordinate == xCo && yCoordinate == yCo)
				datalist[xCoordinate][yCoordinate] = 1;
			else
				datalist[xCoordinate][yCoordinate] = 0;
		}
			
}

void Matrice::getPoint(Matrice obj)
{
	cout << "Position du point.\nX : " << obj.x << endl;
	cout << "Y : " << obj.y << endl;

	double distance = sqrt(pow(obj.x, 2) + pow(obj.y, 2));

	cout << "\nLa distance par rapport a l'origine du repere est : " << distance << endl;
}

void Matrice::dispMatrice()
{
	cout << "\n  0|1|2|3|4" << endl;
	for (int xCoordinate = 0; xCoordinate < tailleX; xCoordinate++)
	{
		cout << xCoordinate << "|";
		for (int yCoordinate = 0; yCoordinate < tailleY; yCoordinate++)
		{
			cout << datalist[xCoordinate][yCoordinate];
			cout << " ";
		}
		cout << endl;
	}
		
}