#pragma once
#include "string"
using namespace std;

#define TAILLESTANDARD 5
#define STOP 0
#define CONTINUE 1
#define ERREURTAILLE 123
#define ERREURINTEXISTS 456

class CSetInt
{
private:
	int m_dTailleMax;					//Taille maximale du tableau d'entiers.
	int *m_tTab;						//Tableau d'entiers.
	int m_dIndex;						//Position courante au sein du tableau d'entiers.
public:
	CSetInt();							//Constructeur par d�faut.
	CSetInt(int dInt);					//Constructeur sur base d'une taille maximale pr�d�finie.
	~CSetInt();
	int Get_TailleMax() const throw();
	int Get_dIndex() const throw();
	void Set_TailleMax(int dTaille);
	void Set_dindex(int dIndex);
	void fctAddInt(int dAdd);			//Ajout d'un entier dans le tableau et contr�le de l'espace disponible.
	void fctIfIntExist(int dIntTest);	//Contr�le de la pr�sence d'un entier dasn le tableau.
	void fctShowTable() const throw();
};

