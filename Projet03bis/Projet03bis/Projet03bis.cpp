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
		catch (exception const& oE)
		{
			cerr << "Erreur : " << oE.what() << endl;
		}
	}
	cout << tab1.fctShowTable() << endl;
return 0;
}
