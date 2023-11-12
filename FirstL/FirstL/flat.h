#pragma once
#include <fstream>
#include "figures.h"
#include "keeper.h"
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

class Flat : public Figures {
private:
	string figure;      //Тип фигуры 
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, R;
	double S, AB, BC, CD, DE, AC, AD, AE;
public:
	Flat();
	~Flat();
	Flat(const Flat&);
	void setVal() override;
	Flat(string figure, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5,
		double S, double AB, double BC, double CD, double DE, double AC, double AD, double AE, Flat& obj);

	void Build4(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF color);
	void Build3(int x1, int y1, int x2, int y2, int x3, int y3, COLORREF color);
	void Build5(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, COLORREF color);
	void Build0(int x1, int y1, int R, COLORREF color);


	void dlina3(Flat& obj, int x1, int y1, int x2, int y2, int x3, int y3);
	void dlina4(Flat& obj, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	void dlina5(Flat& obj, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5);

	friend ofstream& operator << (ofstream& fout, Flat& obj);
	friend ifstream& operator >> (ifstream& fin, Flat& obj);

	friend ostream& operator << (ostream& out, Flat& obj);
	friend istream& operator >> (istream& in, Flat& obj);

	Flat& operator =(const Flat& other);
};