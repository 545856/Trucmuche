#include "stdafx.h"
#include "CSetInt.h"

#include <iostream>
using namespace std;

int fctMenu(CSetInt *tab1);

int main()
{
	CSetInt oCSetInt1(TAILLESTANDARD);
	do
	{
		//system("cls");
		cout << endl << "\t--- MANIPULATION D'UN TABLEAU D'ENTIERS ---" << endl << endl;
		cout << "--- PART 1 ---" << endl;
		cout << "[1] Entrer un nouvel entier positif." << endl;
		cout << "[2] Afficher le tableau." << endl;
		cout << "[3] Lancer une insertion automatiquer pour tester la taille max du tableau." << endl;
		cout << "--- PART 2 ----" << endl;
		cout << "[4] Tester le constructeur de copie" << endl;
		cout << "[5] Tester la surcharge de l'operateur d'assignation" << endl;
		cout << "[6] Tester la surcharge de l'operateur de cast" << endl;
		cout << "[0] Sortir du programme." << endl;
	} while (fctMenu(&oCSetInt1) != STOP);
	
	/*CSetInt oCSetInt2(oCSetInt1);
	oCSetInt2.fctShowTable();
	CSetInt oCSetInt3;	//Surcharge de l'opérateur d'assignation
	oCSetInt3 = oCSetInt1;
	oCSetInt3.fctShowTable();
	dSommeEntiers = int(oCSetInt3); //Surcharge de l'opérateur de cast
	cout << dSommeEntiers << endl;*/

	return 0;
}

//
int fctMenu(CSetInt *oCSetInt1)
{
	int dChoix;

	cout << "Votre choix : ";
	cin >> dChoix;
	cout << endl;

	if (dChoix == 4)
	{
		CSetInt *oCSetInt2 = new CSetInt(*oCSetInt1);
		oCSetInt2->fctShowTable();
		return CONTINUE;
	}
	if (dChoix == 5)
	{
		CSetInt *oCSetInt3 = new CSetInt;
		*oCSetInt3 = *oCSetInt1;
		oCSetInt3->fctShowTable();
	}
	if (dChoix = 6)
	{
		int dSommeEntiers;
		dSommeEntiers = int(*oCSetInt3); //Surcharge de l'opérateur de cast
		cout << dSommeEntiers << endl;
	}

	switch (dChoix)
	{
	case 0:												// Fin du programme.
		cout << "Fin du programme." << endl;
		return STOP;
	case 1:													// Insertion d'un entier dans le tableau.
		cout << "Entier : ";
		cin >> dChoix;

		try
		{
			oCSetInt1->fctAddInt(dChoix);					// Insertion d'un nouvel entier dans le tableau.
		}													// Contrôle : espace disponible et éventuel  
		catch (exception const& oE)							// présence de l'entier.
		{
			cerr << "Erreur : " << oE.what() << endl;
		}
		return CONTINUE;
	case 2:													// Affichage du tableau.
		oCSetInt1->fctShowTable();
		return CONTINUE;
	case 3:													// Insertion d'une chaîne d'entier dans le tableau
		for (int i = 0; i < TAILLESTANDARD + 1; i++)		// jusqu'à atteindre la taille maximale.
		{
			try
			{
				oCSetInt1->fctAddInt(i + 1);
			}
			catch (exception const& oE)
			{
				cerr << "Erreur : " << oE.what() << endl;
			}
		}
		return CONTINUE;
	case 4:													//Tester le constructeur par copie
	case 5:													//Surcharge de l'opérateur d'assignation
		return CONTINUE;
	case 6:
	default:
		cout << "Choix non valide, fin du programme" << endl;// Fin du programme.
		return STOP;
	}
}