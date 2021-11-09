#include <iostream>
#include "Classe.h"
#include "Classe.cpp"

using namespace std;

void Exercice1()
{
    Voiture* voiture1 = new Voiture(324,12);
    Voiture* voiture2 = new VoitureSport(156, 8);

    voiture1->accelerer();
    voiture2->accelerer();

    (voiture1 = voiture2)->accelerer();
}

void Exercice2()
{
    Instrument* instrument;

    int choixInstrument = 0;

    while (choixInstrument != 3)
    {
        cout << "1 - Saxophone\n2 - Piano\n3 - Quitter l'exercice" << endl;
        cout << "Veuillez choisir votre instrument : ";
        cin >> choixInstrument;

        if (choixInstrument == 1)
            instrument = new Saxophone();

        if (choixInstrument == 2)
            instrument = new Piano();

        else
        {
            cout << "Ce choix n'existe pas !\nVotre choix d'instrument : ";
            cin >> choixInstrument;
        }
    }
}

void Exercice3()
{
    VoitureLavage* voiture1, * voiture2, * moto1;
    StationLavage stationLavage(3);

    voiture1 = new VoitureLavage();
    voiture2 = new VoitureLavage();
    moto1 = new MotoLavage();

    stationLavage.add(voiture1);
    stationLavage.add(voiture2);
    stationLavage.add(moto1);
    stationLavage.laverLeParc();

    voiture1 = moto1;
    stationLavage.update(0, voiture1);
    stationLavage.laverLeParc();
}

int main()
{
    int choixExo = 0;

    while (choixExo != 4)
    {
        cout << "1 - Exercice 1\n2 - Exercice 2\n3 - Exercice 3" << endl;
        cout << "Veuillez choisir l'exercice que vous voulez faire : ";
        cin >> choixExo;

        if (choixExo == 1)
            Exercice1();

        if (choixExo == 2)
            Exercice2();

        if (choixExo == 3)
            Exercice3();

        else
        {
            cout << "Ce choix n'existe pas !\nVotre choix d'exercice : ";
            cin >> choixExo;
        }
    }
    
}


