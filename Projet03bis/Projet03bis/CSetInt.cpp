#include "stdafx.h"
#include "CSetInt.h"
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
	m_dTailleMax= dInt;
	m_dIndex = 0;
}
CSetInt::~CSetInt()
{
	cout << "Suppression du tableau d'entiers.";
	free(m_tTab);
}
//....................
// Getters & Setters .
//....................
int CSetInt::Get_TailleMax()
{
	return m_dTailleMax;
}
/*int CSetInt::Get_tTab()
{
	return m_tTab;
}*/
int CSetInt::Get_dIndex()
{
	return m_dIndex;
}
void CSetInt::Set_TailleMax(int dTaille)
{
	m_dTailleMax = dTaille;
}
/*void CSetInt::Set_tTab(int *tTab)
{
}*/
void CSetInt::Set_dindex(int dIndex)
{
	m_dIndex = dIndex;
}
//............................
// Fonctions de manipulation .
//............................
bool CSetInt::fctAddInt(int dAdd)
{
	if (!fctIfIntExist(dAdd) && m_dIndex < m_dTailleMax)
	{
		m_tTab[m_dIndex] = dAdd;
		m_dIndex++;
		return true;
	}
	else
	{
		return false;
	}
}
bool CSetInt::fctIfIntExist(int dIntTest)
{
	int i; 

	for (i = 0; i < m_dIndex; i++)
	{
		if (m_tTab[i] == dIntTest)
		{
			return true;
		}
	}
	return false;
}
//..........................................
// Fonction d'affichage d'un tableau d'int .
//..........................................
int CSetInt::fctShowTable()
{
	cout << "Tableau d'entiers :" << endl;
	for (int i = 0; i < m_dIndex; i++)
	{
		cout << m_tTab[i] << " ";
	}
	cout << endl;

	return 0;
}