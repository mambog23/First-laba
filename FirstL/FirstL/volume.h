#pragma once
#include <fstream>
#include "figures.h"
#include "keeper.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

class Volume : public Figures {
private:
	string figure;      //Тип фигуры 
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, R, z1, z2, z3, z4, z5, x6, y6, z6;
	double V, AB, BC, CD, DE, AC, AD, AE, BD, BE, CF, EF, DF, CE;
public:
	Volume();
	~Volume();
	Volume(const Volume&);
	void setVal() override;
	void push(const Volume& obj);
	Volume(string figure, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6,
		double V, double AB, double BC, double CD, double DE, double AC, double AD, double AE, double BD,
		double BE, double CF, double EF, double DF, double CE, Volume& obj);

	//Тетраэдр
	void Build_tet(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF color);
	void dlina_tet(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4);
	void Vtet(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4);

	//Призма
	void Build_priz(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
		int x5, int y5, int x6, int y6, COLORREF color);
	void dlina_priz(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4,
		int x5, int y5, int z5, int x6, int y6, int z6);
	void Vpriz(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4,
		int x5, int y5, int z5, int x6, int y6, int z6);

	//Пирамида
	void Build_pir(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, COLORREF color);
	void dlina_pir(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4,
		int x5, int y5, int z5);
	void Vpir(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4,
		int x5, int y5, int z5);


	friend ofstream& operator << (ofstream& fout, Volume& obj);
	friend ifstream& operator >> (ifstream& fin, Volume& obj);

	friend ostream& operator << (ostream& out, Volume& obj);
	friend istream& operator >> (istream& in, Volume& obj);

	Volume& operator =(const Volume& other);

};