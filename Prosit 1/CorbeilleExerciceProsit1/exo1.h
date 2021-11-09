#include <ostream>
#include <string>

class listData
{
public :
	listData();
	void addData();
	void inputData(int _value);
	int sommeData();
	int moyenneData();
	int minData();
	int maximumData();
	int variationMax();

private :
	int newValue;
	int nbrData;
};