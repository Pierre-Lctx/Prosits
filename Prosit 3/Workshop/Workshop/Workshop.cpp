#include <iostream>
#include "Classe.h"
#include "Classe.cpp"

int main()
{
    string numLicense, modele, location;
    int dateVehicule;

    Exercice1::Accident* tableauAccident[3];
    
    for (int i = 0; i < 3; i++)
    {
        cout << "\nVeuillez rentrer votre numero de license : ";
        cin >> numLicense;

        cout << "\nVeuillez rentrer le modele du vehicule : ";
        cin >> modele;

        cout << "\nVeuillez rentrer la date de construction de votre vehicule : ";
        cin >> dateVehicule;

        Exercice1::Car voiture1(numLicense, modele, dateVehicule);

        cout << "\nVeuillez rentrer votre numero de license : ";
        cin >> numLicense;

        cout << "\nVeuillez rentrer le modele du vehicule : ";
        cin >> modele;

        cout << "\nVeuillez rentrer la date de construction de votre vehicule : ";
        cin >> dateVehicule;

        Exercice1::Car voiture2(numLicense, modele, dateVehicule);

        cout << "\nVeuillez rentrer lla localisation de l'accident : ";
        cin >> location;

        Exercice1::Accident(i + 1, location, voiture1, voiture2);
        
    }
    
    for (int y = 0; y < 3; y++)
    {
        tableauAccident[y]->toString();
    }
}
