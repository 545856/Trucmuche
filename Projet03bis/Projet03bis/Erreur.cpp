#include "stdafx.h"
#include "CSetInt.h"

#include "iostream"
using namespace std;

//...............................
// Constructeurs et destructeur .
//...............................
Erreur::Erreur(int dNumero, string const& strPhrase, int dNiveau) noexcept(true)
{
	m_dNumeroErreur = dNumero;
	m_strMessageErreur = strPhrase;
	m_dNiveauErreur = dNiveau;
}
Erreur::~Erreur() throw()
{
	//cout << "Renitialisation message d'erreur" << endl;
}
//....................
// Getters & Setters .
//....................
const char* Erreur::what() const noexcept(true)
{
	return m_strMessageErreur.c_str();
}
int Erreur::getNiveauErreur() const noexcept(true)
{
	return m_dNiveauErreur;
}
int Erreur::getNumeroErreur() const noexcept(true)
{
	return m_dNumeroErreur;
}
