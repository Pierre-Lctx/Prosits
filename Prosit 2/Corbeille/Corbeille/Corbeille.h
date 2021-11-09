#ifndef Corbeille_HEADER
#define Corbeille_HEADER

#pragma once
#include "corbeilleHeader.h"


class Exercice1
{
public:
    Exercice1() {}
    void lire(string fileName, string inputMessage);
    string afficher(string fileName);

    void lireBinaire(string fileName, string message, int sizeOfMessage);
    string afficherBinaire(string fileName, int sizeOfMessage);

private :
    //Déclaration du fichier en écriture seule
    ofstream fichierEcriture;
    //Déclaration du fichier en lecture seule
    ifstream fichierLecture;
    //Déclaration de la variable du message
    string message;
    //Déclaration du fichier
    FILE* file;
};

class Cesar
{
public :
    Cesar();
    string crypter(string messageParametre);
    string decrypter(string messageParametre);

private :
    string messageDecrypte, messageEncrypte, alphabet;
    int cle;
};

class Exercice4
{
public :
    char XOR(char caractere, char cle);
};

namespace NS_composants
{
    class CLaddition
    {
    public :
        double addition(double*, int);
    };

    class CLfacture
    {
    public :
        void imprimerFacture(double, double, double);
    };

    class CLtva
    {
    private :
        const double TVA = 1.20;

    public :
        double calculTVA(double);
    };
}

namespace NS_svc
{
    class serviceCalcul
    {
    private :
        NS_composants::CLaddition* objetAddition;
        NS_composants::CLtva* objetTVA;
        double grilleCouts[3];

    public :
        serviceCalcul(void);
        double* calculerMontantTTC(double*, int);
    };

    class serviceFichier
    {
    private :
        NS_composants::CLfacture* facture;

    public :
        serviceFichier(void);
        void imprimerFacture(double, double, double);
    };
}

namespace NS_client
{
    class ihm
    {
    public :
        void run();

    private :
        NS_svc::serviceCalcul* calcul;
        NS_svc::serviceFichier* fichier;
    };
}

#endif



