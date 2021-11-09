#ifndef Classe_HEADER
#define Classe_HEADER

#include <ostream>
#include <string>

using namespace std;

class Voiture
{
protected :
	int vitesseMax, vitesse, acceleration;
	static int nbrVoitureCrees;
	void initialisation_objet(int, int);

public :
	Voiture();
	Voiture(int, int);
	virtual void accelerer(void);
};

class VoitureSport : public Voiture
{
private:
	void initialisation_obj(int, int);

public:
	VoitureSport(void);
	VoitureSport(int, int);
	void accelerer(void);
};

//Exercice 2

class Instrument
{
public:
	virtual void jouer(void);
};

class Saxophone : public Instrument
{
	void jouer(void) { cout << "Saxo" << endl; }
};

class Piano : public Instrument
{
	void jouer(void) { cout << "Piano" << endl; };
};

class VoitureLavage
{
public:
	virtual void lavage(void) { cout << "La voiture  " << this << " vient d'etre lavee ! " << endl; }
};

class MotoLavage : public VoitureLavage
{
public:
	void lavage(void) { cout << "La moto  " << this << " vient d'etre lavee !" << endl; }
};

class StationLavage
{
private:
	VoitureLavage** emplacements;
	int taille;
	int index;
public:
	StationLavage(int taille)
	{
		this->emplacements = new VoitureLavage* [taille];
		this->taille = taille;
		this->index = 0;
	}
	void add(VoitureLavage* voiture)
	{
		this->emplacements[this->index] = voiture;
		this->index++;
	}
	void update(int index, VoitureLavage* voiture)
	{
		this->emplacements[index] = voiture;
	}
	void laverLeParc(void)
	{
		int i;

		for (i = 0; i < this->taille; i++)
		{
			this->emplacements[i][0].lavage();
		}
	}
};
#endif