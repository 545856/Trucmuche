#pragma once
#include "exception"
#include "string"
using namespace std;
#define TAILLESTANDARD 5

class CSetInt
{
private:
	int m_dTailleMax;
	int *m_tTab;
	int m_dIndex;

public:
	CSetInt();
	CSetInt(int dInt);
	~CSetInt();

	int Get_TailleMax();
	//int Get_tTab();
	int Get_dIndex();

	void Set_TailleMax(int dTaille);
	void Set_dindex(int dIndex);
	//void Set_tTab(int *tTab);

	void fctAddInt(int dAdd);
	void fctIfIntExist(int dIntTest);
	int fctShowTable();
};

class Erreur : public exception
{
private:
	int m_dNumeroErreur;
	string m_strMessageErreur;
	int m_dNiveauErreur;

public:
	Erreur(int dNumero = 0, string const& strPhrase = "", int dNiveau = 0)
		throw()
		: m_dNumeroErreur(dNumero), m_strMessageErreur(strPhrase), m_dNiveauErreur(dNiveau)
	{}
	virtual const char* what() const throw()
	{
		return m_strMessageErreur.c_str();
	}

	int getNiveauErreur() const throw()
	{
		return m_dNiveauErreur;
	}

	virtual ~Erreur() throw()
	{}
};
