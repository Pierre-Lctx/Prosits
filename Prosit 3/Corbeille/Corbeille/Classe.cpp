#include "Classe.h"
#include <ostream>
#include <string>

int Voiture::nbrVoitureCrees = 0;

Voiture::Voiture()
{
	this->initialisation_objet(100, 3);
}

Voiture::Voiture(int newVitesseMax, int newAcceleration)
{
	this->initialisation_objet(newVitesseMax, newAcceleration);
}

void Voiture::initialisation_objet(int newVitesseMax, int newAcceleration)
{
	if (newVitesseMax > 100)
		this->vitesseMax = 100;

	else
		this->vitesseMax = newVitesseMax;

	if (newAcceleration > 3)
		this->acceleration = 3;

	else
		this->acceleration = newAcceleration;

	Voiture::nbrVoitureCrees++;

	this->vitesse = 0;

	cout << "Voiture numero " << Voiture::nbrVoitureCrees << " fini !";
}

void Voiture::accelerer()
{
	for (int i = 0; this->vitesse < this->vitesseMax; i++)
	{	
		cout << "Vitesse : " << this->vitesse << endl;
		this->vitesse += this->acceleration;
	}
}

VoitureSport::VoitureSport()
{
	this->initialisation_obj(200, 8);
}

VoitureSport::VoitureSport(int newVitesseMax, int newAcceleration)
{
	this->initialisation_obj(newVitesseMax, newAcceleration);
}

void VoitureSport::initialisation_obj(int newVitesseMax, int newAcceleration)
{
	if (newVitesseMax > 200)
		this->vitesseMax = 200;

	else
		this->vitesseMax = newVitesseMax;

	if (newAcceleration > 8)
		this->acceleration = 8;

	else
		this->acceleration = newAcceleration;
}

void VoitureSport::accelerer()
{
	for (int i = 0; this->vitesse < this->vitesseMax; i++)
	{
		cout << "Vitesse : " << this->vitesse << endl;
		this->vitesse += this->acceleration;
	}
}