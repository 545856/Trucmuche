#pragma once
#include "exception"
#include "string"
using namespace std;

#define TAILLESTANDARD 5
#define STOP 0
#define CONTINUE 1

class CSetInt
{
private:
	int m_dTailleMax;						//Taille maximale du tableau d'entiers.
	int *m_tTab;							//Tableau d'entiers.
	int m_dIndex;							//Position courante au sein du tableau d'entiers.
public:
	//C'tor & d'tor
	CSetInt();								//Constructeur par d�faut.
	CSetInt(int dInt);						//Constructeur sur base d'une taille maximale pr�d�finie.
	CSetInt(const CSetInt &oCSetInt);		//Constructeur de copie.
	~CSetInt();
	//Surcharge des op�rateurs
	operator int() const;					//Surcharge de l'op�rateur de cast entype int.
	CSetInt operator = (const CSetInt &oCestInt);	//Surcharche de l'op�rateur d'assignation pour un objet de type CSetInt.
	//Pr�dicats
	int Get_TailleMax() const throw();
	int Get_dIndex() const throw();
	void fctShowTable() const throw();
	//Actions
	void Set_TailleMax(int dTaille);
	void Set_dindex(int dIndex);
	void fctAddInt(int dAdd);				//Ajout d'un entier dans le tableau et contr�le de l'espace disponible.
	void fctIfIntExist(int dIntTest);		//Contr�le de la pr�sence d'un entier dasn le tableau.	
};

class Erreur : public exception
{
private:
	int m_dNumeroErreur;
	string m_strMessageErreur;
	int m_dNiveauErreur;
public:
	Erreur(int dNumero, string const& strPhrase, int dNiveau) throw();	//Constructeur reprenant un numero d'erreur, un message d'erreur et un niveau d'erreur.
	virtual ~Erreur() throw();											//D�constructeur 
	virtual const char* what() const throw();							//Affichage d'un message d'erreur
	int getNiveauErreur() const throw();
	int getNumeroErreur() const throw();
};
