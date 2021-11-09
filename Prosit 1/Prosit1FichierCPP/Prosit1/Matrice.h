#ifndef Matrice_HEADER
#define Matrice_HEADER

#include <ostream>
#include <string>
#include <list>

class Matrice
{
public:
	Matrice();
	Matrice(int newTailleX, int newTailleY);
	void setPoint(int xCo, int yCo);
	void getPoint(Matrice obj);
	void dispMatrice();
	
	int **datalist;
private:
	int tailleX, tailleY, x, y;
	

};


#endif // !1
