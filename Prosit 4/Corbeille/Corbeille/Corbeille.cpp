#include "Classe.h"
#include "Classe.cpp"

//Exercice 1

void fonction(void)                         
{
    cout << "Premiere fonction" << endl;
}

typedef void (*fonctionDeux)(void);
fonctionDeux pointerFunction;

void Exercice1()
{
    pointerFunction = &fonction;
    pointerFunction();
}

//Exercice 2

void fonction1(void)
{
    cout << "Premiere fonction" << endl;
}

void fonction2(void)
{
    cout << "Deuxieme fonction" << endl;
}

void fonction3(void)
{
    cout << "Troisieme fonction" << endl;
}

typedef void (*fonctionExo2)(void);
fonctionExo2 pointerFunctionExo2[3];

void Exercice2()
{
    pointerFunctionExo2[0] = &fonction1;
    pointerFunctionExo2[1] = &fonction2;
    pointerFunctionExo2[2] = &fonction3;

    for (int i = 0; i < 3; i++)
        pointerFunctionExo2[i]();
}

//Exercice 3
//Pour cet exercice, nous reprennons les fonctions de l'exercice 2

typedef void(*fonctionPointer)(void);
fonctionPointer* pointerFunctionExo3;

void Exercice3()
{
    cout << "Exercice 3\n" << endl;

    pointerFunctionExo3 = new fonctionPointer[3];
    pointerFunctionExo3[0] = &fonction1;
    pointerFunctionExo3[1] = &fonction2;
    pointerFunctionExo3[2] = &fonction3;

    for (int i = 0; i < 3; i++)
    {
        pointerFunctionExo3[i]();
    }
}

//Exercice 4
//Pour cet exercice, nous reprennons les fonctions de l'exercice 2

typedef void(*fonctionExercice4)(void);
fonctionExercice4 nbrFonction[3], *processus;

void Exercice4()
{
    int nombreFonction, rang;

    nbrFonction[0] = &fonction1;
    nbrFonction[1] = &fonction2;
    nbrFonction[2] = &fonction3;

    cout << "Veuillez rentrer le nombre de fonctions dans le processus : ";
    cin >> nombreFonction;

    processus = new fonctionExercice4[3];
    rang = 0;

    for (int i = 0; i < nombreFonction; i++)
    {
        cout << "Veuillez indiquer le numéro de la prochaine fonction : ";
        cin >> rang;

        processus[i] = nbrFonction[rang];
    }

    for (int i = 0; i < nombreFonction; i++)
        processus[i]();

}


//Exercice 5

void Exercice5()
{
    A objA;
    B objB;

    objA.m();
}

//Exercice 6

typedef struct Person
{
    int age;
    string firstName;
    Person *next;
}P;


void afficher(P* list)                     //Création d'une fonction d'affichage des personnes
{
    while (list != NULL)
    {
        cout << list->firstName << " " << list->age << endl;
        list = list->next;
    }
}             

void Exercice6()
{
    P* begin;
    P firstPerson, secondPerson, thirdPerson;

    begin = &firstPerson;                   //On commence avec la première personne
    
    firstPerson.age = 4;
    firstPerson.firstName = "Toto";
    firstPerson.next = &secondPerson;       // La prochaine personne est la deuxième personne

    secondPerson.age = 75;
    secondPerson.firstName = "Zébulon";
    secondPerson.next = &thirdPerson;       // La prochaine personne est la troisième personne

    thirdPerson.age = 32;
    thirdPerson.firstName = "Richard";
    thirdPerson.next = NULL;                //Il n'y a pas d'autres personnes

    afficher(begin);
}

//Exercice 7

P* listOfPerson;
P* save;

void afficher(P* list)                     //Création d'une fonction d'affichage des personnes
{
    listOfPerson = save;

    while (list != NULL)
    {
        cout << list->firstName << " " << list->age << endl;
        list = list->next;
    }
}

void ajouter(P* rank)                       //Fonction pour ajouter une personne
{
    if (listOfPerson == NULL)
    {
        listOfPerson = rank;
        save = listOfPerson;
    }
    else
    {
        listOfPerson->next = rank;
        listOfPerson = listOfPerson->next;
    }
}

void Exercice7()
{
    P person1, person2, person3, person4;

    person1.age = 2;
    person1.firstName = "Personne 1";
    person1.next = NULL;

    person2.age = 4;
    person2.firstName = "Personne 2";
    person2.next = NULL;

    person3.age = 6;
    person3.firstName = "Personne 3";
    person3.next = NULL;

    person4.age = 8;
    person4.firstName = "Personne 4";
    person4.next = NULL;

    ajouter(&person1);
    ajouter(&person2);
    ajouter(&person3);
    ajouter(&person4);

    afficher(listOfPerson);
}

//Exercice 8

void Exercice8()
{
    A8* p;

    for (int i = 0; i < 100000; i++)
    {
        p = new A8(10);
        delete p;
    }
}

int main()
{
    Exercice6();
}

