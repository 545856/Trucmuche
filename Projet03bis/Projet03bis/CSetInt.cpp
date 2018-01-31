#include "stdafx.h"
#include "CSetInt.h"

#include "iostream"
using namespace std;

//...............................
// Constructeurs et destructeur .
//...............................
CSetInt::CSetInt()
{
	m_tTab = (int*)malloc(sizeof(int) * TAILLESTANDARD);
	m_dTailleMax = TAILLESTANDARD;
	m_dIndex = 0;
}
CSetInt::CSetInt(int dInt)
{
	m_tTab = (int*)malloc(sizeof(int) * dInt);
	m_dTailleMax = dInt;
	m_dIndex = 0;
}
CSetInt::CSetInt(const CSetInt& oCSetInt)
{
	m_tTab = (int*)malloc(sizeof(int) * TAILLESTANDARD);
	m_dIndex = oCSetInt.m_dIndex;
	m_dTailleMax = oCSetInt.m_dTailleMax;
	for (int i = 0; i < m_dIndex; i++)
	{
		m_tTab[i] = oCSetInt.m_tTab[i];
	}
}
CSetInt::~CSetInt()
{
	cout << "Suppression du tableau d'entiers." << endl;
	free(m_tTab);
}
//...........................
// Surcharge des opérateurs .
//...........................
CSetInt CSetInt::operator = (const CSetInt& oCSetInt)
{
	this->m_tTab = (int*)malloc(sizeof(int) * TAILLESTANDARD);
	this->m_dIndex = oCSetInt.m_dIndex;
	this->m_dTailleMax = oCSetInt.m_dTailleMax;
	for (int i = 0; i < this->m_dIndex; i++)
	{
		this->m_tTab[i] = oCSetInt.m_tTab[i];
	}
	return *this;
}
CSetInt::operator int() const
{
	return 3;
}
//....................
// Getters & Setters .
//....................
int CSetInt::Get_TailleMax() const throw()
{
	return m_dTailleMax;
}
int CSetInt::Get_dIndex() const throw()
{
	return m_dIndex;
}
void CSetInt::Set_TailleMax(int dTaille)
{
	m_dTailleMax = dTaille;
}
void CSetInt::Set_dindex(int dIndex)
{
	m_dIndex = dIndex;
}
//............................
// Fonctions de manipulation .
//............................
void CSetInt::fctAddInt(int dAdd)
{
	if (m_dIndex >= m_dTailleMax)
	{
		throw Erreur(123, "Taille max atteinte", 2);
	}

	fctIfIntExist(dAdd);
	m_tTab[m_dIndex] = dAdd;
	m_dIndex++;
}
void CSetInt::fctIfIntExist(int dIntTest)
{
	int i;

	for (i = 0; i < m_dIndex; i++)
	{
		if (m_tTab[i] == dIntTest)
		{
			throw Erreur(456, "Entier deja present", 2);
		}
	}
}
//..........................................
// Fonction d'affichage d'un tableau d'int .
//..........................................
void CSetInt::fctShowTable() const throw()
{
	cout << "Tableau d'entiers :" << endl;
	for (int i = 0; i < m_dIndex; i++)
	{
		cout << m_tTab[i] << " ";
	}
	cout << endl;

	return;
}