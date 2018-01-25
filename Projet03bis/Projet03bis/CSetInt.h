#pragma once
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


