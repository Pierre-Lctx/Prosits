

#include <iostream>
#include <string>
#include <list>
#include "Matrice.h"
#include "Matrice.cpp"

using namespace std;

int prositSansObjet()
{
    int tailleMatrice = 5;

    int xCoordinate;                                //Création de la coordonnée x du point à placer
    int yCoordinate;                                //Création de la coordonnée y du point à placer

    cout << "La taille de la matrice est " << tailleMatrice << "x" << tailleMatrice << ".";

    cout << "Ou voulez vous placer votre point ?" << endl;
    cout << "Coordonnees en X : ";
    cin >> xCoordinate;                             //Saisie de x

    cout << "\nCoordonnees en Y : ";
    cin >> yCoordinate;                             //Saisie de y
   
    //Creation de la matrice en faisant de l'allocation dynamique
    int** matrice2D = new int* [tailleMatrice];     //Etat : Matrice 1D

    for (int i = 0; i < tailleMatrice; i++)
        matrice2D[i] = new int[tailleMatrice];      //Etat : Matrice 2D
    
    cout << "  0|1|2|3|4" << endl;

    for (int x = 0; x < tailleMatrice; x++)
    {

        for (int y = 0; y < tailleMatrice; y++)
        {
            if (xCoordinate == x && yCoordinate == y)
                matrice2D[x][y] = 1;                   //Remplissage de la matrice par des 1, placement du point
            else
                matrice2D[x][y] = 0;                   //Remplissage de la matrice par des 0
            cout << matrice2D[x][y];
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}

void prositAvecObjet()
{
    Matrice matrice2D;

    int xCoordinate;                                //Création de la coordonnée x du point à placer
    int yCoordinate;                                //Création de la coordonnée y du point à placer

    cout << "La taille de la matrice est 5x5.";

    cout << "Ou voulez vous placer votre point ?" << endl;
    cout << "Coordonnees en X : ";
    cin >> xCoordinate;                             //Saisie de x

    cout << "\nCoordonnees en Y : ";
    cin >> yCoordinate;                             //Saisie de y

    matrice2D.setPoint(xCoordinate, yCoordinate);
    matrice2D.getPoint(matrice2D);

    matrice2D.dispMatrice();
}

int main()
{
   
    prositAvecObjet();
    
}