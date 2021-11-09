#include "Classe.h"

using namespace std;

Point::Point()
{
	x = y = z = 0;
}

void Point::setPoint(int inputX, int inputY, int inputZ)
{
	x = inputX;
	y = inputY;
	z = inputZ;
}

int Point::getPoint(char co)
{
	if (co == 'x')
		return x;
	if (co == 'y')
		return y;
	if (co == 'z')
		return z;
}

void Parcours::setParcours(Point point1, Point point2, string Mode)
{
	if (Mode == "2D")
		distance = sqrt(pow((point1.getPoint('x') - point2.getPoint('x')), 2) + pow((point1.getPoint('y') - point2.getPoint('y')), 2));
	if (Mode == "3D")
		distance = sqrt(pow((point1.getPoint('x') - point2.getPoint('x')), 2) + pow((point1.getPoint('y') - point2.getPoint('y')), 2) + pow((point1.getPoint('z') - point2.getPoint('z')), 2));

	cout << "\nLa distance parcourue est : " << distance << endl;
}