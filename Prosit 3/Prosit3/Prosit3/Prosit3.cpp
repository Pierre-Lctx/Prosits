#include <iostream>
#include "Classe.h"
#include "Classe.cpp"


int main()
{
    Point point1;
    Point point2;

    int choixMode, choixConversion;

    Parcours parcours;

    cout << "Voulez utiliser un point 2D ou 3D ?" << endl;
    cout << "1 - 2D" << endl;
    cout << "2 - 3D" << endl;

    cin >> choixMode;

    if (choixMode == 1)
    {
        int xCo1, yCo1, xCo2, yCo2;

        cout << "Coordonnée en x du point 1 : ";
        cin >> xCo1;

        cout << "Coordonnée en y du point 1 : ";
        cin >> yCo1;

        cout << "Coordonnée en x du point 2 : ";
        cin >> xCo2;

        cout << "Coordonnée en y du point 2 : ";
        cin >> yCo2;

        point1.setPoint(xCo1, yCo1, 0);
        point2.setPoint(xCo2, yCo2, 0);

        parcours.setParcours(point1, point2, "2D");

        cout << "Voulez vous convertir votre point 2D en 3D ?" << endl;
        cout << "1 - Oui" << endl;
        cout << "2 - Non" << endl;

        cin >> choixConversion;

        if (choixConversion == 1)
        {
            int zCo1, zCo2;

            cout << "Coordonnée en z du point 1 : ";
            cin >> zCo1;

            cout << "Coordonnée en z du point 2 : ";
            cin >> zCo2;

            point1.setPoint(xCo1, yCo1, zCo1);
            point2.setPoint(xCo2, yCo2, zCo2);

            parcours.setParcours(point1, point2, "3D");
        }

        while (choixConversion != 2)
        {
            cout << "Ce choix n'existe pas !\nVotre choix : ";
            cin >> choixConversion;
        }
    }

    if (choixMode == 1)
    {
        int xCo1, yCo1, zCo1, xCo2, yCo2, zCo2;

        cout << "Coordonnée en x du point 1 : ";
        cin >> xCo1;

        cout << "Coordonnée en y du point 1 : ";
        cin >> yCo1;

        cout << "Coordonnée en z du point 1 : ";
        cin >> zCo1;

        cout << "Coordonnée en x du point 2 : ";
        cin >> xCo2;

        cout << "Coordonnée en y du point 2 : ";
        cin >> yCo2;

        cout << "Coordonnée en z du point 2 : ";
        cin >> zCo2;

        point1.setPoint(xCo1, yCo1, zCo1);
        point2.setPoint(xCo2, yCo2, zCo2);

        parcours.setParcours(point1, point2, "3D");

        cout << "Voulez vous convertir votre point 3D en 2D ?" << endl;
        cout << "1 - Oui" << endl;
        cout << "2 - Non" << endl;

        cin >> choixConversion;

        if (choixConversion == 1)
        {
            point1.setPoint(xCo1, yCo1, 0);
            point2.setPoint(xCo2, yCo2, 0);

            parcours.setParcours(point1, point2, "2D");
        }

        while (choixConversion != 2)
        {
            cout << "Ce choix n'existe pas !\nVotre choix : ";
            cin >> choixConversion;
        }
    }

    
}

