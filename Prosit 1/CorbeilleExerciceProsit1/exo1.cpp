#include <ostream>
#include "exo1.h"

using namespace std;

listData::listData()
{
	newValue = 0;
	nbrData = 0;
}

listData::addData()
{
	cout << "Combien de donnees voulez vous ajouter : ";
	cin >> nbrData;

	for (int i = 0; i < nbrDataToAdd; i++)
	{
		cout << "Veuillez ajouter votre donnée : " << endl;
		cin >> newValue;


	}
	
}