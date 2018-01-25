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
	int m_dTailleMax;					//Taille maximale du tableau d'entiers.
	int *m_tTab;						//Tableau d'entiers.
	int m_dIndex;						//Position courante au sein du tableau d'entiers.
public:
	CSetInt();							//Constructeur par défaut.
	CSetInt(int dInt);					//Constructeur sur base d'une taille maximale prédéfinie.
	~CSetInt();			
	int Get_TailleMax() const throw();	
	int Get_dIndex() const throw();
	void Set_TailleMax(int dTaille);
	void Set_dindex(int dIndex);
	void fctAddInt(int dAdd);			//Ajout d'un entier dans le tableau et contrôle de l'espace disponible.
	void fctIfIntExist(int dIntTest);	//Contrôle de la présence d'un entier dasn le tableau.
	void fctShowTable() const throw();
};

class Erreur : public exception
{
private:
	int m_dNumeroErreur;
	string m_strMessageErreur;
	int m_dNiveauErreur;
public:
	Erreur(int dNumero, string const& strPhrase, int dNiveau) throw();	//Constructeur reprenant un numero d'erreur, un message d'erreur et un niveau d'erreur.
	virtual ~Erreur() throw();											//Déconstructeur 
	virtual const char* what() const throw();							//Affichage d'un message d'erreur
	int getNiveauErreur() const throw();								
	int getNumeroErreur() const throw();
};
