#pragma once
#include <ostream>
#include <string>
#include <list>
#include <bitset>
#include <fstream>
#include "Classe.h"

Classes::Cesar::Cesar()
{
    messageEncrypte = "";
    messageDecrypte = "";
    cle = 3;
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

string Classes::Cesar::crypter(string messageParametre)
{
    for (int rangMot = 0; rangMot < messageParametre.size(); rangMot++)
    {
        char lettre = messageParametre[rangMot];
        for (int rang = 0; rang < 26; rang++)
        {
            if (lettre == alphabet[rang])
            {
                messageEncrypte += alphabet[rang - cle];
            }
        }
    }

    cout << "Message de base : " << messageParametre << endl;
    cout << "Message Encrypte : " << messageEncrypte << endl;

    return messageEncrypte;
}

string Classes::Cesar::decrypter(string messageParametre)
{
    for (int rangMot = 0; rangMot < messageParametre.size(); rangMot++)
    {
        char lettre = messageParametre[rangMot];
        for (int rang = 0; rang < 26; rang++)
        {
            if (lettre == alphabet[rang])
            {
                messageDecrypte += alphabet[rang + cle];
            }
        }
    }

    cout << "Message de base : " << messageParametre << endl;
    cout << "Message decrypte : " << messageDecrypte << endl;

    return messageDecrypte;
}

char Classes::cryptageXOR::XOR(char caractere, char cle)
{
    char resultat;

    resultat = caractere ^ cle;

    return resultat;
}

void programme::prosit::run()
{
    int choixMode = 0;
    
    ofstream writingFile;                                   //Fichier dans lequel nous allons écrire le message crypté
    ifstream readingFile;                                   //Fichier dans lequel nous allons lire le message de base

    string writingFileName, readingFileName;

    while (choixMode != 4)
    {
        cout << "Veuillez choisir votre mode :" << endl;
        cout << "1 - Cryptage en Cesar";
        cout << "2 - Cryptage en XOR";
        cout << "3 - Cryptage en Cesar et XOR";
        cout << "4 - Fermer l'application";
        cin >> choixMode;

        cout << "Veuillez rentrer le nom du fichier de depart :";
        cin >> readingFileName;

        cout << "Veuillez rentrer le nom du fichier d'arrivee : ";
        cin >> writingFileName;

        if (choixMode == 1)
        {
            string message;

            readingFile.open(readingFileName.c_str());
            writingFile.open(writingFileName.c_str());

            if (readingFile && writingFile)
            {
                string ligne;

                while (getline(readingFile, ligne))
                {
                    message.append(ligne);
                }
                writingFile << _Cesar->crypter(message);
            }
            else
                cout << "ERREUR : Impossible d'ouvrir le fichier.";

            writingFile.close();
            readingFile.close();
        }

        if (choixMode == 2)
        {
            string message;

            readingFile.open(readingFileName.c_str());
            writingFile.open(writingFileName.c_str());

            if (readingFile && writingFile)
            {
                string ligne;

                while (getline(readingFile, ligne))
                {
                    message.append(ligne);

                    for (char letter : message)
                    {
                        bitset<8> foo(_cryptageXOR->XOR(letter, 'o'));

                        writingFile << foo << '\n';
                    }
                }
            }
            else
                cout << "ERREUR : Impossible d'ouvrir le fichier.";

            writingFile.close();
            readingFile.close();
        }

        if (choixMode == 3)
        {
            string message;

            readingFile.open(readingFileName.c_str());
            writingFile.open(writingFileName.c_str());

            if (readingFile && writingFile)
            {
                string ligne;

                while (getline(readingFile, ligne))
                {
                    message.append(ligne);
                }
                for (char letter : _Cesar->crypter(message))
                {
                    bitset<8> foo(_cryptageXOR->XOR(letter, 'o'));

                    writingFile << foo << '\n';
                }
            }
            else
                cout << "ERREUR : Impossible d'ouvrir le fichier.";

            writingFile.close();
            readingFile.close();
        }

        if (choixMode < 1 || choixMode > 3)
        {
            cout << "Ce choix n'existe pas !\nVeuillez rentrer un autre choix !\n\nVotre nouveau choix : ";
            cin >> choixMode;
        }
    }
    
   
}