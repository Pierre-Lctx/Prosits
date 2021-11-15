#ifndef Classe_HEADER
#define Classe_HEADER

#pragma once
#include <ostream>
#include <iostream>

using namespace std;

//Exericice 5

typedef void(*functionClass)(void);
functionClass event;

class A
{
public:
	void m(void)
	{
		cout << "Nous sommes dans la classe A !" << endl;
		event();
	}
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
		cout << "Nous sommes dans la classe B !" << endl;
	}
};

//Exercice 8

class A8
{
private :
	int* t;

public :
	A8(int tailleTab)
	{
		t = new int[tailleTab];
	}
	~A8(void)
	{
		delete[]t;
	}
};
#endif