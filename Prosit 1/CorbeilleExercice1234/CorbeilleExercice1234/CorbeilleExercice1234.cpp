#include <iostream>
#include <list>

using namespace std;

class CLvoiture
{
public:
	CLvoiture();
	CLvoiture(int newVitesseMax, int newAcceleration);
	CLvoiture(CLvoiture& voiture)
	{
		acceleration = voiture.acceleration;
		vitesse = voiture.vitesse;
		vitesseMax = voiture.vitesseMax;
		idV = voiture.idV;
		idVoiture = voiture.idVoiture;
	}
	int getAcceleration() { return acceleration; }
	int getVitesseMax() { return vitesseMax; }
	int getID() { return idV; }
	int setAcceleration(int newAcceleration) { acceleration = newAcceleration; }
	int setVitesseMax(int newVitesseMax) { vitesseMax = newVitesseMax; }
	void ini_obj(int iniAcceleration, int iniVitesseMax)
	{
		iniAcceleration = acceleration;
		iniVitesseMax = vitesseMax;
	}
	void accelerer() { cout << "Acceleration" << endl; }

private:
	int vitesseMax, vitesse, acceleration, idV, idVoiture;
};

CLvoiture::CLvoiture()
{

}

CLvoiture::CLvoiture(int newVitesseMax, int newAcceleration)
{
	vitesseMax = newVitesseMax;
	acceleration = newAcceleration;
}

class Cla
{
public:
	//Partie exercice 3
	Cla();
	Cla(int parametre);


	//Partie exercice 2
	void afficher(void)
	{
		cout << "bonjour" << endl;
	}
};

Cla::Cla()
{

}

Cla::Cla(int parametre)
{

}

class CLobjet
{
private : 
	double masse, vitesse, ec;
	void init()
	{
		masse = 2;
		vitesse = 5;
		ec = 0.5f * masse * pow(vitesse, 2);
	}

public : 
	double GetMasse() { cout << "Masse : " << masse << endl; return masse; }
	double GetVitesse() { cout << "Vitesse : " << vitesse << endl;  return vitesse; }
	double GetEc() const { return ec; }

	CLobjet()
	{
		init();
	}
	CLobjet(int newMasse, int newVitesse);
	CLobjet(const CLobjet& parametre)
	{
		masse = parametre.masse;
		vitesse = parametre.vitesse;
		ec = parametre.ec;
	}

	void cheatInit(int newMasse, int newVitesse)
	{
		masse = newMasse;
		vitesse = newVitesse;
	}
	
	void Calculer(void)
	{
		ec = 0.5f * masse * vitesse * vitesse;
	}

	void Comparer(CLobjet obj1, CLobjet obj2)
	{
		if (obj1.ec > obj2.ec)
			cout << "L'energie cinetique de l'objet 1 est plus grande !" << endl;
		else
			cout << "L'energie cinetique de l'objet 2 est plus grande !" << endl;
	}
};


CLobjet::CLobjet(int newMasse, int newVitesse)
{
	masse = newMasse;
	vitesse = newVitesse;
}

void Exercice1()
{
	Cla o1;
	Cla* o2;

	o2 = new Cla;

	o1.afficher();
	o2->afficher();

	cout << "Adresse de o1 : " << &o1 << endl;
	cout << "Adresse de o2 : " << &o2 << endl;

	cout << "Adresse pointée de o2 : " << o2 << endl;

	cout << "Taille du type Cla : " << sizeof(Cla) << endl;

	cout << "Taille en octet de o1 : " << sizeof(o1) << endl;
	cout << "Taille en octet de o2 : " << sizeof(o2) << endl;

	delete o2;

}

void Exercice2()
{
	CLobjet object1;
	CLobjet object2;

	object1.Comparer(object1, object2);
}

void Exercice3()
{
	CLobjet o1;
	CLobjet o2(2, 2);

	CLobjet* o3 = new CLobjet;
	CLobjet* o4;

	o3->cheatInit(4, 32);

	o4 = o3;

	o1.Calculer();
	o2.Calculer();
	o1.Comparer(o1, o2);

	o3->Calculer();
	o4->Calculer();
	o3->Comparer(*o3, *o4);

	o4->GetMasse();
	o4->GetVitesse();
}

void Exercice4()
{
	CLvoiture voiture1(120, 20);
	CLvoiture voiture2(140, 30);
	CLvoiture* voiture3 = new CLvoiture;

	voiture1.accelerer();
	voiture2.accelerer();
	voiture3->accelerer();
}

int main()
{
	cout << "Exercice 1 :" << endl;
	Exercice1();
	cout << "\nExercice 2 :" << endl;
	Exercice2();
	cout << "\nExercice 3 :" << endl;
	Exercice3();
	cout << "\nExercice 4 :" << endl;
	Exercice4();
}
