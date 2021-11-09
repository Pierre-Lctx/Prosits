#ifndef Classe_HEADER
#define Classe_HEADER

#include <ostream>

using namespace std;

class Point
{
private :
	int x, y, z;

public :
	Point();
	void setPoint(int inputX, int inputY, int inputZ);
	int getPoint(char co);
};

class Parcours : public Point
{
private :
	Point* obj;
	double distance;

public :
	void setParcours(Point point1, Point point2, string Mode);
};

#endif