#include "volume.h"
#include <iostream>
#include <string>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

Volume::Volume(string figure, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6,
	double V, double AB, double BC, double CD, double DE, double AC, double AD, double AE, double BD,
	double BE, double CF, double EF, double DF, double CE, Volume& obj) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора с параметром для класса Volume" << endl << endl;
	obj.figure = figure;
	obj.x1 = x1;
	obj.y1 = y1;
	obj.x2 = x2;
	obj.y2 = y2;
	obj.x3 = x3;
	obj.y3 = y3;
	obj.x4 = x4;
	obj.y4 = y4;
	obj.x5 = x5;
	obj.y5 = y5;
	obj.x6 = x6;
	obj.y6 = y6;

	obj.V = V;
	obj.AB = AB;
	obj.BC = BC;
	obj.CD = CD;
	obj.DE = DE;
	obj.AC = AC;
	obj.AD = AD;
	obj.AE = AE;

	obj.BD = BD;
	obj.BE = BE;
	obj.CF = CF;
	obj.EF = EF;
	obj.DF = DF;
	obj.CE = CE;
}

Volume::Volume() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса Volume" << endl << endl;
	figure = "";
	x1 = y1 = x2 = y2 = x3 = y3 = x4 = y4 = x5 = y5 = AB = BC = CD = DE = AC = AD = AE = V = BD = 0;
	z1 = z2 = z3 = z4 = z5 = 0;
	x6 = y6 = z6 = 0;
	BE = CF = EF = DF = 0;
	CE = 0;
}

Volume::Volume(const Volume& other) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса Volume" << endl << endl;
	*this = other;
}

Volume::~Volume() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов деструктора для класса Volume" << endl << endl;
}

void Volume::setVal() {
	cin >> *this;
}

ifstream& operator>>(ifstream& fin, Volume& obj) { // Функция чтения файла объекта (volume)
	fin >> obj.figure >> obj.x1 >> obj.y1 >> obj.z1 >>
		obj.x2 >> obj.y2 >> obj.z2 >>
		obj.x3 >> obj.y3 >> obj.z3 >>
		obj.x4 >> obj.y4 >> obj.z4 >>
		obj.x5 >> obj.y5 >> obj.z5 >>
		obj.x6 >> obj.y6 >> obj.z6;
	fin >> obj.AB >> obj.BC >> obj.CD >> obj.DE >> obj.AC >> obj.AD >> obj.AE >> obj.BD >> obj.BE >> obj.CF >>
		obj.EF >> obj.DF >> obj.CE;
	fin >> obj.V;
	return fin;
}

Volume& Volume::operator=(const Volume& other) {
	this->figure = other.figure;
	this->x1 = other.x1;
	this->y1 = other.y1;
	this->z1 = other.z1;
	this->x2 = other.x2;
	this->y2 = other.y2;
	this->z2 = other.z2;
	this->x3 = other.x3;
	this->y3 = other.y3;
	this->z3 = other.z3;
	this->x4 = other.x4;
	this->y4 = other.y4;
	this->z4 = other.z4;
	this->x5 = other.x5;
	this->y5 = other.y5;
	this->z5 = other.z5;
	this->x6 = other.x6;
	this->y6 = other.y6;
	this->z6 = other.z6;


	this->AB = other.AB;
	this->BC = other.BC;
	this->CD = other.CD;
	this->DE = other.DE;
	this->AC = other.AC;
	this->AD = other.AD;
	this->AE = other.AE;
	this->BD = other.BD;
	this->DE = other.BE;
	this->CF = other.CF;
	this->EF = other.EF;
	this->DF = other.DF;
	this->CE = other.CE;

	this->V = other.V;
	return *this;
}

ofstream& operator<<(ofstream& fout, Volume& obj) { // Функция записи в файл объекта(volume)
	fout << obj.figure << endl;
	fout << obj.x1 << endl;
	fout << obj.y1 << endl;
	fout << obj.z1 << endl;
	fout << obj.x2 << endl;
	fout << obj.y2 << endl;
	fout << obj.z2 << endl;
	fout << obj.x3 << endl;
	fout << obj.y3 << endl;
	fout << obj.z3 << endl;
	fout << obj.x4 << endl;
	fout << obj.y4 << endl;
	fout << obj.z4 << endl;
	fout << obj.x5 << endl;
	fout << obj.y5 << endl;
	fout << obj.z5 << endl;
	fout << obj.x6 << endl;
	fout << obj.y6 << endl;
	fout << obj.z6 << endl;

	fout << obj.AB << endl;
	fout << obj.BC << endl;
	fout << obj.CD << endl;
	fout << obj.DE << endl;
	fout << obj.AC << endl;
	fout << obj.AD << endl;
	fout << obj.AE << endl;
	fout << obj.BD << endl;
	fout << obj.BE << endl;
	fout << obj.CF << endl;
	fout << obj.EF << endl;
	fout << obj.DF << endl;
	fout << obj.CE << endl;

	fout << obj.V << endl;
	fout << endl;
	return fout;
}

ostream& operator<<(ostream& out, Volume& obj) { // Функция вывода на экран данных объекта(volume)
	setlocale(LC_ALL, "Russian");
	out << "Тип фигуры: " << obj.figure << endl;
	out << "Координаты:" << endl;
	out << "(" << obj.x1 << ", " << obj.y1 << ", " << obj.z1 << ")" << endl;
	if (obj.x2 != 0 && obj.y2 != 0) out << "(" << obj.x2 << ", " << obj.y2 << ", " << obj.z2 << ")" << endl;
	if (obj.x3 != 0 && obj.y3 != 0) out << "(" << obj.x3 << ", " << obj.y3 << ", " << obj.z3 << ")" << endl;
	if (obj.x4 != 0 && obj.y4 != 0) out << "(" << obj.x4 << ", " << obj.y4 << ", " << obj.z4 << ")" << endl;
	if (obj.x5 != 0 && obj.y5 != 0)	out << "(" << obj.x5 << ", " << obj.y5 << ", " << obj.z5 << ")" << endl;
	if (obj.x6 != 0 && obj.y6 != 0)	out << "(" << obj.x6 << ", " << obj.y6 << ", " << obj.z6 << ")" << endl;

	if (obj.AB != 0) out << "AB = " << obj.AB << endl;
	if (obj.BC != 0) out << "BC = " << obj.BC << endl;
	if (obj.CD != 0) out << "CD = " << obj.CD << endl;
	if (obj.DE != 0) out << "DE = " << obj.DE << endl;
	if (obj.AC != 0) out << "AC = " << obj.AC << endl;
	if (obj.AD != 0) out << "AD = " << obj.AD << endl;
	if (obj.AE != 0) out << "AE = " << obj.AE << endl;
	if (obj.BD != 0) out << "BD = " << obj.BD << endl;
	if (obj.BE != 0) out << "BE = " << obj.BE << endl;
	if (obj.CF != 0) out << "CF = " << obj.CF << endl;
	if (obj.EF != 0) out << "EF = " << obj.EF << endl;
	if (obj.DF != 0) out << "DF = " << obj.DF << endl;
	if (obj.CE != 0) out << "CE = " << obj.CE << endl;

	out << "V = " << obj.V << endl;
	Volume v;
	//initwindow(700, 500); // инициализация окна 
	if (obj.x5 == 0 && obj.y5 == 0 && obj.x6 == 0 && obj.y6 == 0)
		v.Build_tet(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4, 13);
	if (obj.x4 != 0 && obj.y4 != 0 && obj.x5 != 0 && obj.y5 != 0 && obj.x6 == 0 && obj.y6 == 0)
		v.Build_pir(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4, obj.x5, obj.y5, 13);
	if (obj.x4 != 0 && obj.y4 != 0 && obj.x5 != 0 && obj.y5 != 0 && obj.x6 != 0 && obj.y6 != 0)
		v.Build_priz(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4, obj.x5, obj.y5, obj.x6, obj.y6, 13);
	//system("pause");
	//closegraph(); // выход из графического режима
	return out;
}

istream& operator>>(istream& in, Volume& obj) { // Функция ввода данных объекта (volume)
	Volume v;
	int button;
	bool flag = true; // Для проверки логических условий (флаг состояний), как выключатель - ВКЛ и ВЫКЛ
	while (flag) {
		system("cls"); // Ждет ввода, чтобы окно консоли не закрылось
		cout << "Меню: " << endl << endl;
		cout << "1 - Тетраэдр" << endl;
		cout << "2 - Призма" << endl;
		cout << "3 - Пирамида" << endl;
		cout << "0 - Выход из программы" << endl << endl;
		cout << "Выберите пункт: ";
		cin >> button;

		if (cin.fail()) { // Проверка на правильный ввод
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			cout << "Тетраэдр" << endl;
			cout << "Тип фигуры: ";
			cin >> obj.figure;
			cout << "x1 = ";
			cin >> obj.x1;
			cout << "y1 = ";
			cin >> obj.y1;
			cout << "z1 = ";
			cin >> obj.z1;
			cout << "x2 = ";
			cin >> obj.x2;
			cout << "y2 = ";
			cin >> obj.y2;
			cout << "z2 = ";
			cin >> obj.z2;
			cout << "x3 = ";
			cin >> obj.x3;
			cout << "y3 = ";
			cin >> obj.y3;
			cout << "z3 = ";
			cin >> obj.z3;
			cout << "x4 = ";
			cin >> obj.x4;
			cout << "y4 = ";
			cin >> obj.y4;
			cout << "z4 = ";
			cin >> obj.z4;
			//obj.x5 = obj.y5 = obj.z5 = 0;
			//obj.x6 = obj.y6= obj.z6 = 0;
			//obj.DE = obj.AE = obj.BE = obj.CF = obj.EF = obj.DF = obj.CE = 0;
			v.Build_tet(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4, 13);
			v.dlina_tet(obj, obj.x1, obj.y1, obj.z1, obj.x2, obj.y2, obj.z2, obj.x3, obj.y3, obj.z3, obj.x4, obj.y4, obj.z4);
			v.Vtet(obj, obj.x1, obj.y1, obj.z1, obj.x2, obj.y2, obj.z2, obj.x3, obj.y3, obj.z3, obj.x4, obj.y4, obj.z4);
			break;
		case 2:
			cout << "Призма" << endl;
			cout << "Тип фигуры: ";
			cin >> obj.figure;
			cout << "x1 = ";
			cin >> obj.x1;
			cout << "y1 = ";
			cin >> obj.y1;
			cout << "z1 = ";
			cin >> obj.z1;
			cout << "x2 = ";
			cin >> obj.x2;
			cout << "y2 = ";
			cin >> obj.y2;
			cout << "z2 = ";
			cin >> obj.z2;
			cout << "x3 = ";
			cin >> obj.x3;
			cout << "y3 = ";
			cin >> obj.y3;
			cout << "z3 = ";
			cin >> obj.z3;
			cout << "x4 = ";
			cin >> obj.x4;
			cout << "y4 = ";
			cin >> obj.y4;
			cout << "z4 = ";
			cin >> obj.z4;
			cout << "x5 = ";
			cin >> obj.x5;
			cout << "y5 = ";
			cin >> obj.y5;
			cout << "z5 = ";
			cin >> obj.z5;
			cout << "x6 = ";
			cin >> obj.x6;
			cout << "y6 = ";
			cin >> obj.y6;
			cout << "z6 = ";
			cin >> obj.z6;
			//obj.CD = obj.AE = obj.BD = obj.CE = 0;
			v.Build_priz(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4,
				obj.x5, obj.y5, obj.x6, obj.y6, 13);
			v.dlina_priz(obj, obj.x1, obj.y1, obj.z1, obj.x2, obj.y2, obj.z2, obj.x3, obj.y3, obj.z3, obj.x4, obj.y4, obj.z4,
				obj.x5, obj.y5, obj.z5, obj.x6, obj.y6, obj.z6);
			v.Vpriz(obj, obj.x1, obj.y1, obj.z1, obj.x2, obj.y2, obj.z2, obj.x3, obj.y3, obj.z3, obj.x4, obj.y4, obj.z4,
				obj.x5, obj.y5, obj.z5, obj.x6, obj.y6, obj.z6);
			break;
		case 3:
			cout << "Пирамида" << endl;
			cout << "Тип фигуры: ";
			cin >> obj.figure;
			cout << "x1 = ";
			cin >> obj.x1;
			cout << "y1 = ";
			cin >> obj.y1;
			cout << "z1 = ";
			cin >> obj.z1;
			cout << "x2 = ";
			cin >> obj.x2;
			cout << "y2 = ";
			cin >> obj.y2;
			cout << "z2 = ";
			cin >> obj.z2;
			cout << "x3 = ";
			cin >> obj.x3;
			cout << "y3 = ";
			cin >> obj.y3;
			cout << "z3 = ";
			cin >> obj.z3;
			cout << "x4 = ";
			cin >> obj.x4;
			cout << "y4 = ";
			cin >> obj.y4;
			cout << "z4 = ";
			cin >> obj.z4;
			cout << "x5 = ";
			cin >> obj.x5;
			cout << "y5 = ";
			cin >> obj.y5;
			cout << "z5 = ";
			cin >> obj.z5;
			//obj.x6 = obj.y6 = obj.z6 = 0;
			//obj.AC = obj.BD = obj.CF = obj.EF = obj.DF = 0;
			v.Build_pir(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4, obj.x5, obj.y5, 13);
			v.dlina_pir(obj, obj.x1, obj.y1, obj.z1, obj.x2, obj.y2, obj.z2, obj.x3, obj.y3, obj.z3, obj.x4, obj.y4, obj.z4,
				obj.x5, obj.y5, obj.z5);
			v.Vpir(obj, obj.x1, obj.y1, obj.z1, obj.x2, obj.y2, obj.z2, obj.x3, obj.y3, obj.z3, obj.x4, obj.y4, obj.z4,
				obj.x5, obj.y5, obj.z5);
			break;
		case 4:

			break;
		case 0:
			flag = false; // Выход из программы
			cout << "\nКонец" << endl;
			break;
		default:
			cout << endl << "Некорректные данные, введите заново!" << endl
				<< endl; // Проверка на правильный ввод
			system("pause");
			break;
		}
		return in;
	}
	//return in;
}


//Тетраэдр
void Volume::Build_tet(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF color) {
	initwindow(700, 500); // инициализация окна 
	setcolor(13);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x4, y4, x1, y1);
	line(x1, y1, x3, y3);
	line(x2, y2, x4, y4);
	system("pause");
	closegraph(); // выход из графического режима
}

void Volume::dlina_tet(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4) {
	obj.AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	obj.BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2));
	obj.AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) + (z3 - z1) * (z3 - z1));
	obj.AD = sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1) + (z4 - z1) * (z4 - z1));
	obj.BD = sqrt((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2) + (z4 - z2) * (z4 - z2));
	obj.CD = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3) + (z4 - z3) * (z4 - z3));
}

void Volume::Vtet(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4) {
	double ABX, ABY, ABZ;
	double ADX, ADY, ADZ;
	double ACX, ACY, ACZ;

	ABX = x2 - x1;
	ABY = y2 - y1;
	ABZ = z2 - z1;

	ADX = x4 - x1;
	ADY = y4 - y1;
	ADZ = z4 - z1;

	ACX = x3 - x1;
	ACY = y3 - y1;
	ACZ = z3 - z1;

	double p = ABX * ADY * ACZ;
	double w = ADX * ACY * ABZ;
	double e = ABY * ADZ * ACX;

	double r = ABZ * ADY * ACX;
	double t = ADX * ABY * ACZ;
	double y = ADZ * ACY * ABX;

	double a = p + w + e;
	double b = r + t + y;
	double g = a - b;

	obj.V = 0.167 * g;
}

//Призма
void Volume::Build_priz(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,
	int x5, int y5, int x6, int y6, COLORREF color) {
	initwindow(700, 500); // инициализация окна 
	setcolor(13);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x4, y4, x1, y1);
	line(x1, y1, x3, y3);

	line(x2, y2, x5, y5);
	line(x3, y3, x6, y6);
	line(x4, y4, x5, y5);
	line(x5, y5, x6, y6);
	line(x4, y4, x6, y6);
	system("pause");
	closegraph(); // выход из графического режима
}

void Volume::dlina_priz(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4,
	int x5, int y5, int z5, int x6, int y6, int z6) {
	obj.AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	obj.BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2));
	obj.AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) + (z3 - z1) * (z3 - z1));
	obj.AD = sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1) + (z4 - z1) * (z4 - z1));

	obj.BE = sqrt((x2 - x5) * (x2 - x5) + (y2 - y5) * (y2 - y5) + (z2 - z5) * (z2 - z5));
	obj.CF = sqrt((x6 - x3) * (x6 - x3) + (y6 - y3) * (y6 - y3) + (z6 - z3) * (z6 - z3));
	obj.DE = sqrt((x5 - x4) * (x5 - x4) + (y5 - y4) * (y5 - y4) + (z5 - z4) * (z5 - z4));
	obj.EF = sqrt((x5 - x6) * (x5 - x6) + (y5 - y6) * (y5 - y6) + (z5 - z6) * (z5 - z6));
	obj.DF = sqrt((x4 - x6) * (x4 - x6) + (y4 - y6) * (y4 - y6) + (z4 - z6) * (z4 - z6));
}

void Volume::Vpriz(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4,
	int x5, int y5, int z5, int x6, int y6, int z6) {
	double ABX, ABY, ABZ;
	double ADX, ADY, ADZ;
	double ACX, ACY, ACZ;

	ABX = x2 - x1;
	ABY = y2 - y1;
	ABZ = z2 - z1;

	ADX = x4 - x1;
	ADY = y4 - y1;
	ADZ = z4 - z1;

	ACX = x3 - x1;
	ACY = y3 - y1;
	ACZ = z3 - z1;

	double p = ABX * ADY * ACZ;
	double w = ADX * ACY * ABZ;
	double e = ABY * ADZ * ACX;

	double r = ABZ * ADY * ACX;
	double t = ADX * ABY * ACZ;
	double y = ADZ * ACY * ABX;

	double a = p + w + e;
	double b = r + t + y;
	double g = a - b;

	obj.V = 0.5 * g;
}

//Пирамида
void Volume::Build_pir(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, COLORREF color) {
	initwindow(700, 500); // инициализация окна 
	setcolor(13);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x4, y4, x1, y1);
	line(x1, y1, x5, y5);
	line(x2, y2, x5, y5);
	line(x3, y3, x5, y5);
	line(x4, y4, x5, y5);
	system("pause");
	closegraph(); // выход из графического режима
}

void Volume::dlina_pir(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4,
	int x5, int y5, int z5) {
	obj.AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	obj.BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2));
	obj.CD = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3) + (z4 - z3) * (z4 - z3));
	obj.AD = sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1) + (z4 - z1) * (z4 - z1));
	obj.AE = sqrt((x5 - x1) * (x5 - x1) + (y5 - y1) * (y5 - y1) + (z5 - z1) * (z5 - z1));
	obj.BE = sqrt((x2 - x5) * (x2 - x5) + (y2 - y5) * (y2 - y5) + (z2 - z5) * (z2 - z5));
	obj.CE = sqrt((x3 - x5) * (x3 - x5) + (y3 - y5) * (y3 - y5) + (z3 - z5) * (z3 - z5));
	obj.DE = sqrt((x5 - x4) * (x5 - x4) + (y5 - y4) * (y5 - y4) + (z5 - z4) * (z5 - z4));
}

void Volume::Vpir(Volume& obj, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4,
	int x5, int y5, int z5) {
	double ABX, ABY, ABZ;
	double AEX, AEY, AEZ;
	double ACX, ACY, ACZ;

	ABX = x2 - x1;
	ABY = y2 - y1;
	ABZ = z2 - z1;

	AEX = x5 - x1;
	AEY = y5 - y1;
	AEZ = z5 - z1;

	ACX = x3 - x1;
	ACY = y3 - y1;
	ACZ = z3 - z1;

	double p = ABX * AEY * ACZ;
	double w = AEX * ACY * ABZ;
	double e = ABY * AEZ * ACX;

	double r = ABZ * AEY * ACX;
	double t = AEX * ABY * ACZ;
	double y = AEZ * ACY * ABX;

	double a = p + w + e;
	double b = r + t + y;
	double g = a - b;

	obj.V = 0.167 * g;
}