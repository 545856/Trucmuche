#include "stdafx.h"
#include "CSetInt.h"

#include <iostream>
using namespace std;

int fctMenu(CSetInt *tab1);

int main()
{
	CSetInt oCSetInt1(TAILLESTANDARD);
	int dSommeEntiers;

	do
	{
		//system("cls");
		cout << endl << "\t ---MANIPULATION D'UN TABLEAU D'ENTIERS---" << endl << endl;
		cout << "[1] Entrer un nouvel entier positif." << endl;
		cout << "[2] Afficher le tableau." << endl;
		cout << "[3] Lancer une insertion automatiquer pour tester la taille max du tableau." << endl;
		cout << "[4] Creer une copie d'un tableau d'entiers et l'afficher." << endl;
		cout << "[0] Sortir du programme." << endl;
	} while (fctMenu(&oCSetInt1) != STOP);

	CSetInt oCSetInt2(oCSetInt1); //Constructeur de copies
	oCSetInt2.fctShowTable();
	
	CSetInt oCSetInt3;	//Surcharge de l'op�rateur d'assignation
	oCSetInt3 = oCSetInt1;
	oCSetInt3.fctShowTable();

	dSommeEntiers = int(oCSetInt3); //Surcharge de l'op�rateur de cast
	cout << dSommeEntiers;

	return 0;
}

//
int fctMenu(CSetInt *tab1)
{
	int dChoix;

	cout << "Votre choix : ";
	cin >> dChoix;
	cout << endl;

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
			tab1->fctAddInt(dChoix);						// Insertion d'un nouvel entier dans le tableau.
		}													// Contr�le : espace disponible et �ventuel  
		catch (exception const& oE)							// pr�sence de l'entier.
		{
			cerr << "Erreur : " << oE.what() << endl;
		}
		return CONTINUE;
	case 2:													// Affichage du tableau.
		tab1->fctShowTable();
		return CONTINUE;
	case 3:													// Insertion d'une cha�ne d'entier dans le tableau
		for (int i = 0; i < TAILLESTANDARD + 1; i++)		// jusqu'� atteindre la taille maximale.
		{
			try
			{
				tab1->fctAddInt(i + 1);
			}
			catch (exception const& oE)
			{
				cerr << "Erreur : " << oE.what() << endl;
			}
		}
		return CONTINUE;
	default:
		cout << "Choix non valide, fin du programme" << endl;// Fin du programme.
		return STOP;
	}
}