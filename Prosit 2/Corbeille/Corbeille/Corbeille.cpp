#include <iostream>
#include <fstream>
#include <string>
#include "Corbeille.h"
#include "corbeilleHeader.h"
#include "function.cpp"

using namespace std;

void Exo1()
{
    Exercice1 obj;

    string originFile;
    string messageToAdd;

    int choix = 0;

    while (choix != 3)
    {
        cout << "Veuillez faire votre choix" << endl;
        cout << "1 - Lire dans un fichier .txt" << endl;
        cout << "2 - Ecrire dans un fichier .txt" << endl;

        cin >> choix;

        cout << "Veuillez rentrer le nom du fichier que vous voulez utiliser : ";

        getline(cin >> ws, originFile);

        if (choix == 1)
            obj.afficher(originFile);
        

        if (choix == 2)
        {
            cout << "Veuillez rentrer le message a ecrire : ";

            getline(cin >> ws, messageToAdd);
            
            obj.lire(originFile, messageToAdd);
        }
        
        if (choix != 1 || choix != 2 || choix != 3)
        {
            cout << "Ce choix n'existe pas !!!\nVeuillez mettre un choix qui existe !\n\nVotre choix : ";
            cin >> choix;
        }        
    }
}

void Exo2()
{
    Exercice1* obj;

    string nomFichier;
    string message = "TEST";
    int tailleFichier = message.size();

    obj = new Exercice1();

    int choix = 0;

    while (choix != 3)
    {
        cout << "Veuillez faire votre choix" << endl;
        cout << "1 - Lire dans un fichier .txt" << endl;
        cout << "2 - Ecrire dans un fichier .txt" << endl;

        cin >> choix;

        cout << "Veuillez rentrer le nom du fichier que vous voulez utiliser : ";

        getline(cin >> ws, nomFichier);

        if (choix == 1)
            obj->afficherBinaire(nomFichier, tailleFichier);


        if (choix == 2)
            obj->lireBinaire(nomFichier, message, tailleFichier);

        if (choix != 1 || choix != 2 || choix != 3)
        {
            cout << "Ce choix n'existe pas !!!\nVeuillez mettre un choix qui existe !\n\nVotre choix : ";
            cin >> choix;
        }
    }
}

void Exo3()
{
    Cesar objMsg;                           //Création de l'objet

    string message;

    int choix = 0;

    while (choix != 3)
    {
        if (choix == 1)
        {
            cout << "Entrez votre message : ";
            getline(cin >> ws, message);            //Lecture du message a encrypter

            objMsg.crypter(message);                //Cryptage du message
        }

        if (choix == 2)
        {
            cout << "Entrez votre message : ";
            getline(cin >> ws, message);            //Lecture du message a encrypter

            objMsg.decrypter(message);
        }

        else if (choix != 1 || choix != 2 || choix != 3)
        {
            cout << "Ce choix n'existe pas !!!\nVeuillez mettre un choix qui existe !\n\nVotre choix : ";
            cin >> choix;
        }
    }
    
}

void Exo4()
{
    Exercice4 obj;                                  //Création de l'objet
    char caractere, cle;                            //Création des variables de clé et de caractère

    cout << "Veuillez rentrer une lettre : ";
    cin >> caractere;                               //Entrée du caractère

    cout << "Veuillez rentrer la cle";
    cin >> cle;                                     //Entrée de la clé

    char result;                                    //Création de la variable result

    result = obj.XOR(caractere, cle);               //On fait appelle à la fonction XOR

    cout << "Resultat : " << result << endl;        //On affiche le resultat
}

void Exo5()
{
    NS_client::ihm programme;
    programme.run();
}

int main()
{
    int choixExo = 0;

    while (choixExo != 3)
    {
        cout << "Veuillez faire votre choix" << endl;
        cout << "1 - Exercice 1" << endl;
        cout << "2 - Exercice 2" << endl;
        cout << "3 - Exercice 3" << endl;
        cout << "4 - Exercice 4" << endl;
        cout << "5 - Exercice 5" << endl;

        cin >> choixExo;

        if (choixExo == 1)
            Exo1();

        if (choixExo == 2)
            Exo2();

        if (choixExo == 3)
            Exo3();

        if (choixExo == 4)
            Exo4();

        if (choixExo == 5)
            Exo5();

        if (choixExo < 1 || choixExo > 5)
        {
            cout << "Ce choix n'existe pas !!!\nVeuillez mettre un choix qui existe !\n\nVotre choix : ";
            cin >> choixExo;
        }
    }

    
}