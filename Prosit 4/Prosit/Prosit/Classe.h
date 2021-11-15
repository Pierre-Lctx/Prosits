#ifndef Classe_HEADER
#define Classe_HEADER

#include <ostream>
#include <iostream>
#include <vector>
#include <string>
#include <future>
#include <random>

using namespace std;

typedef void(*functionClass)(void);
functionClass event;

class A
{
public:
	A(void)
	{
		frequences.clear();
	}
	void m(void)
	{
		cout << "Message envoye !" << endl;
		event();
	}
	unsigned int canalAdd(unsigned int i)
	{
		int newFrequence;

		cout << "Quelle frequence voulez ajouter ?" << endl;
		cin >> newFrequence;

		frequences.push_back(newFrequence);

		return newFrequence;
	}

	void canalPrint()
	{
		if (frequences.size() == 0)
		{
			cout << "Il n'y a pas de frequence enregistrer." << endl;
		}
		else
		{
			cout << "Voici la liste des frequences : " << endl;
			for (int item : frequences)
				cout << item << "Hz"<< endl;
		}
		cout << "\n";
	}

	void canaSelect()
	{
		cout << "La frequence utilisee est " << frequences[rand() % (frequences.size() - 1)] << "Hz." << endl;
	}

	string sendMessage()
	{
		string message;

		cout << "Entrez votre message :";
		getline(cin >> ws, message);

		cout << "Message envoye" << endl;

		return message;
	}

private :
	vector<int> frequences;
	vector<string> motMessage;
};

class B
{
public:
	B(void)
	{
		event = &B::m;
	}
	static void m(void)
	{
		cout << "Message recu !" << endl;
	}

private :
	string recieveMessage;
};

#endif // !Classe_HEADER
