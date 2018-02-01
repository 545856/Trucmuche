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
	m_tTab = (int*)malloc(sizeof(int) * oCSetInt.Get_TailleMax());
	Set_dIndex(oCSetInt.Get_dIndex());
	Set_TailleMax(oCSetInt.Get_TailleMax());

	for (int i = 0; i < Get_dIndex(); i++)
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
	this->Set_dIndex(oCSetInt.Get_dIndex());
	this->Set_TailleMax(oCSetInt.Get_TailleMax());
	
	for (int i = 0; i < this->Get_dIndex(); i++)
	{
		this->m_tTab[i] = oCSetInt.m_tTab[i];
	}
	return *this;
}
CSetInt::operator int() const
{
	int dSommeEntiers = 0;

	cout << "Conversion d'un tableau d'entiers en la somme de ses differents elements" << endl;
		for (int i = 0; i < m_dIndex; i++)
	{
			dSommeEntiers += m_tTab[i];
	}
		return dSommeEntiers;
}
//....................
// Getters & Setters .
//....................
int CSetInt::Get_TailleMax() const noexcept(true)
{
	return m_dTailleMax;
}
int CSetInt::Get_dIndex() const noexcept(true)
{
	return m_dIndex;
}
void CSetInt::Set_TailleMax(int dTaille)
{
	m_dTailleMax = dTaille;
}
void CSetInt::Set_dIndex(int dIndex)
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
void CSetInt::fctShowTable() const noexcept(true)
{
	cout << "Tableau d'entiers :" << endl;
	for (int i = 0; i < m_dIndex; i++)
	{
		cout << m_tTab[i] << " ";
	}
	cout << endl;

	return;
}