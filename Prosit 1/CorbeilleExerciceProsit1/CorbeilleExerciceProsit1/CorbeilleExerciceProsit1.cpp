#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class listData
{
public:
	int value;
	int somme = 0;

	list<int> dataList;

	void addData(int valueToAdd)
	{
		dataList.push_back(valueToAdd);
	}
	int inputData(int _value)
	{
		cout << "Saisir la donnee a ajouter : ";
		cin >> _value;

		return _value;
	}
	int sommeData()
	{
		if (somme != 0)
			somme = 0;

		for (int item : dataList)
			somme += item;

		return somme;
	}
	int moyenneData()
	{
		int somme = sommeData();

		return somme / dataList.size();
	}
	int minData()
	{
		int minimum;
		int lastItem = NULL;
		for (int item : dataList)
		{
			if (lastItem == NULL)
				lastItem = item;
			else
			{
				if (item <= lastItem)
					minimum = item;
				else
					lastItem = item;
			}
		}

		return minimum;
	}
	int maximumData()
	{
		int maximum;
		int lastItem = NULL;
		for (int item : dataList)
		{
			if (lastItem == NULL)
				lastItem = item;
			else
			{
				if (item >= lastItem)
					maximum = item;
				else
					lastItem = item;
			}
		}

		return maximum;
	}
	int variationMax()
	{
		return maximumData() - minData();
	}
	
};

int main()
{
	listData _listData;

	_listData.addData(3);
	_listData.addData(4);
	_listData.addData(13);
	_listData.addData(-1);

	int moyenne = _listData.moyenneData();

	_listData.addData(0);

	int minimum = _listData.minData();
}
