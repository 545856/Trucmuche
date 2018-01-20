#pragma once
#define TAILLESTANDARD 50
#include <iostream>
using namespace std;

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

	bool fctAddInt(int dAdd);
	bool fctIfIntExist(int dIntTest);
	int fctShowTable();
};


