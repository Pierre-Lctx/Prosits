#include "Corbeille.h"
#include "corbeilleHeader.h"

string Exercice1::afficher(string fileName)
{   
    this->message.clear();
    fichierLecture.open(fileName.c_str());

    if (fichierLecture)
    {
        string ligne;

        while (getline(fichierLecture, ligne))
        {
            this->message.append(ligne);
            cout << ligne << endl;
        }
    }
    else
        cout << "ERREUR : Impossible d'ouvrir le fichier.";

    fichierLecture.close();
    
    return this->message;
}

void Exercice1::lire(string fileName, string inputMessage)
{
    
    fichierEcriture.open(fileName.c_str());

    if (fichierEcriture)
    {
        cout << "Fichier " << fileName << " ouvert !" << endl ;

        fichierEcriture << inputMessage;
    }

    cout << "Ecriture reussi !" << endl;

    fichierEcriture.close();
}

void Exercice1::lireBinaire(string fileName, string message, int taille)
{   
    const char* texte = &message[0];
    
    this->file = fopen(fileName.c_str(), "w+b");             //On ouvre le fichier en écriture binaire

    for (int i = 0; i < taille; i++)
        fprintf(file, "%c", texte[i]);              //On écrit toutes les lettres du message dans le fichier

    fclose(file);                                   //On ferme le fichier*/
}

string Exercice1::afficherBinaire(string fileName, int taille)
{
    string stringGetChar, texteFinal;

    file = fopen(fileName.c_str(), "r+b");                   //On ouvre le fichier en lecture binaire
    fseek(file, 0, SEEK_SET);                       //On place le curseur en début de fichier pour être sûr de bien lire tout le contenue du fichier

    for (int i = 0; i < taille; i++)
    {
        stringGetChar = (char)fgetc(file);
        texteFinal.append(stringGetChar);
    }

    fclose(file);                                   //On referme le fichier

    cout << this->message << endl;

    return this->message;
}

//Ecercice 3

Cesar::Cesar()
{
    messageEncrypte = "";
    messageDecrypte = "";
    cle = 3;
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

string Cesar::crypter(string messageParametre)
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

string Cesar::decrypter(string messageParametre)
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

//Exercice 4

char Exercice4::XOR(char caractere, char cle)
{
    char resultat;

    resultat = caractere ^ cle;

    return resultat;
}

//Exercice 5

double NS_composants::CLaddition::addition(double* prix, int taille)
{
    double result;

    result = 0;

    for (int i = 0; i < taille; i++)
    {
        result += prix[i];
    }
    return result;
}

void  NS_composants::CLfacture::imprimerFacture(double  montantHT, double  montantTVA, double montantTTC)
{
    ofstream flux("facture.txt");

    flux << "Total HT : " << montantHT << "\n";
    flux << "TVA : " << montantTVA << "\n";
    flux << "Total TTC : " << montantTTC;

    flux.close();
}

double NS_composants::CLtva::calculTVA(double prixTotalHt)
{
    return NS_composants::CLtva::TVA * prixTotalHt;
}

NS_svc::serviceCalcul::serviceCalcul(void)
{
    this->objetAddition = new NS_composants::CLaddition();
    this->objetTVA = new NS_composants::CLtva();
}
double* NS_svc::serviceCalcul::calculerMontantTTC(double* montantsHT, int taille)
{
    double montantTotalHT, montantTotalTTC, montantTVA;

    montantTotalHT = this->objetAddition->addition(montantsHT, taille);
    montantTotalTTC = this->objetTVA->calculTVA(montantTotalHT);

    montantTVA = montantTotalTTC - montantTotalHT;

    this->grilleCouts[0] = montantTotalHT;  
    this->grilleCouts[1] = montantTVA;  
    this-> grilleCouts[2] = montantTotalTTC;

    return this->grilleCouts;
}

NS_svc::serviceFichier::serviceFichier(void)
{
    this->facture = new NS_composants::CLfacture();
}

void  NS_svc::serviceFichier::imprimerFacture(double  montantHT, double  montantTVA, double montantTTC)
{
    this->facture->imprimerFacture(montantHT, montantTVA, montantTTC);
}

NS_client::ihm::ihm(void)
{
    this->calcul = new NS_svc::serviceCalcul();
    this->fichier = new NS_svc::serviceFichier();
}
void NS_client::ihm::run(void)
{
    int nbArticle;
    double* prixDesArticles;
    double* grille;
    int i;
    int prix;

    cout << "Veuillez entrer le nombre d'article :";
    cin >> nbArticle;

    prixDesArticles = new double[nbArticle];

    for (i = 0; i < nbArticle; i++)
    {
        cout << "Veuillez entrer le prix de l'article " << i + 1 << " :";
        cin >> prix;
        prixDesArticles[i] = prix;
    }

    grille = this->calcul->calculerMontantTTC(prixDesArticles, nbArticle);

    cout << "Total TTC : " << grille[2] << " euros" << endl;
    cout << "Impression de la facture en cours." << endl;

    this->fichier->imprimerFacture(grille[0], grille[1], grille[2]);
    cout << "FINI" << endl;

}