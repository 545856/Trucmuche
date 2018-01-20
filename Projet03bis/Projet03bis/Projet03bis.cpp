#include "stdafx.h"
#include "CSetInt.h"

#define TAILLESTANDARD 50

int main()
{
	CSetInt tab1(TAILLESTANDARD);
	int i;

	cout << "Manipulation d'un tableau d'entiers." << endl;	
	for (i = 0; i < 5 + 1; i++)
	{
		if (!tab1.fctAddInt(i+1))
		{
			cout << "Fin du tableau atteinte" << endl;
		}
	}
	cout << tab1.fctShowTable() << endl;
return 0;
}
