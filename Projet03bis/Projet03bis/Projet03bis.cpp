#include "stdafx.h"
#include "CSetInt.h"

#include <iostream>
using namespace std;


int main()
{
	CSetInt tab1(TAILLESTANDARD);
	int i;

	cout << "Manipulation d'un tableau d'entiers." << endl;	
	for (i = 0; i < 6; i++)
	{
		try
		{
			tab1.fctAddInt(i + 1);
		}
		catch (int dB)
		{
			if (dB == 123)
			{
				cerr << "Erreur : " << dB << " , taille maximale du tableau atteinte." << endl;
			}
			if (dB == 456)
			{
				cerr << "Erreur : " << dB << " , entier deja present dans le tableau." << endl;
			}
		}
	}
	cout << tab1.fctShowTable() << endl;
return 0;
}
