#include "flat.h"
#include <iostream>
#include <string>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

Flat::Flat() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса Flat" << endl << endl;
	figure = "";
	x1 = y1 = x2 = y2 = x3 = y3 = x4 = y4 = x5 = y5 = AB = BC = CD = DE = AC = AD = AE = S = R = 0;
}

Flat::Flat(const Flat& other) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса Flat" << endl << endl;
	*this = other;
}

Flat::~Flat() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов деструктора для класса Flat" << endl << endl;
}

void Flat::setVal() {
	cin >> *this;
}

ifstream& operator>>(ifstream& fin, Flat& obj) { // Функция чтения файла объекта (Работник)
	fin >> obj.figure >> obj.x1 >> obj.y1 >> obj.x2 >> obj.y2 >> obj.x3 >> obj.y3 >> obj.x4 >> obj.y4 >> obj.x5 >> obj.y5;
	fin >> obj.R >> obj.AB >> obj.BC >> obj.CD >> obj.DE >> obj.AC >> obj.AD >> obj.AE >> obj.S;
	return fin;
}

Flat& Flat::operator=(const Flat& other) {
	this->figure = other.figure;
	this->x1 = other.x1;
	this->y1 = other.y1;
	this->x2 = other.x2;
	this->y2 = other.y2;
	this->x3 = other.x3;
	this->y3 = other.y3;
	this->x4 = other.x4;
	this->y4 = other.y4;
	this->x5 = other.x5;
	this->y5 = other.y5;
	this->R = other.R;
	this->AB = other.AB;
	this->BC = other.BC;
	this->CD = other.CD;
	this->DE = other.DE;
	this->AC = other.AC;
	this->AD = other.AD;
	this->AE = other.AE;
	this->S = other.S;
	return *this;
}

ofstream& operator<<(ofstream& fout, Flat& obj) { // Функция записи в файл объекта(Работник)
	fout << obj.figure << endl;
	fout << obj.x1 << endl;
	fout << obj.y1 << endl;
	fout << obj.x2 << endl;
	fout << obj.y2 << endl;
	fout << obj.x3 << endl;
	fout << obj.y3 << endl;
	fout << obj.x4 << endl;
	fout << obj.y4 << endl;
	fout << obj.x5 << endl;
	fout << obj.y5 << endl;
	fout << obj.R << endl;
	fout << obj.AB << endl;
	fout << obj.BC << endl;
	fout << obj.CD << endl;
	fout << obj.DE << endl;
	fout << obj.AC << endl;
	fout << obj.AD << endl;
	fout << obj.AE << endl;
	fout << obj.S << endl;
	fout << endl;
	return fout;
}

ostream& operator<<(ostream& out, Flat& obj) { // Функция вывода на экран данных объекта(Работник)
	setlocale(LC_ALL, "Russian");
	out << "Тип фигуры: " << obj.figure << endl;
	//out << obj.x1 << endl;
	//out << obj.y1 << endl;
	//out << obj.x2 << endl;
	//out << obj.y2 << endl;
	//out << obj.x3 << endl;
	//out << obj.y3 << endl;
	//out << obj.x4 << endl;
	//out << obj.y4 << endl;
	//out << obj.x5 << endl;
	//out << obj.y5 << endl;
	//out << obj.R << endl;
	out << "Координаты:" << endl;
	out << "(" << obj.x1 << ", " << obj.y1 << ")" << endl;
	if (obj.x2 != 0 && obj.y2 != 0) out << "(" << obj.x2 << ", " << obj.y2 << ")" << endl;
	if (obj.x3 != 0 && obj.y3 != 0) out << "(" << obj.x3 << ", " << obj.y3 << ")" << endl;
	if (obj.x4 != 0 && obj.y4 != 0) out << "(" << obj.x4 << ", " << obj.y4 << ")" << endl;
	if (obj.x5 != 0 && obj.y5 != 0)	out << "(" << obj.x5 << ", " << obj.y5 << ")" << endl;
	if (obj.R != 0) out << "R = " << obj.R << endl;
	if (obj.AB != 0) out << "AB = " << obj.AB << endl;
	if (obj.BC != 0) out << "BC = " << obj.BC << endl;
	if (obj.CD != 0) out << "CD = " << obj.CD << endl;
	if (obj.DE != 0) out << "DE = " << obj.DE << endl;
	if (obj.AC != 0) out << "AC = " << obj.AC << endl;
	if (obj.AD != 0) out << "AD = " << obj.AD << endl;
	if (obj.AE != 0) out << "AE = " << obj.AE << endl;
	out << "S = " << obj.S << endl;
	return out;
}

istream& operator>>(istream& in, Flat& obj) { // Функция ввода данных объекта (Работник)
	Flat f;
	int button;
	bool flag = true; // Для проверки логических условий (флаг состояний), как выключатель - ВКЛ и ВЫКЛ
	while (flag) {
		system("cls"); // Ждет ввода, чтобы окно консоли не закрылось
		cout << "Меню: " << endl << endl;
		cout << "1 - Четырехугольник" << endl;
		cout << "2 - Треугольник" << endl;
		cout << "3 - Пятиугольник" << endl;
		cout << "4 - Окружность" << endl;
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
			cout << "Четырехугольник" << endl;
			cout << "Тип фигуры: ";
			cin >> obj.figure;
			cout << "x1 = ";
			cin >> obj.x1;
			cout << "y1 = ";
			cin >> obj.y1;
			cout << "x2 = ";
			cin >> obj.x2;
			cout << "y2 = ";
			cin >> obj.y2;
			cout << "x3 = ";
			cin >> obj.x3;
			cout << "y3 = ";
			cin >> obj.y3;
			cout << "x4 = ";
			cin >> obj.x4;
			cout << "y4 = ";
			cin >> obj.y4;
			//obj.x5 = obj.y5 = obj.R = obj.AC = obj.AE = 0;
			f.Build4(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4, 13);
			f.dlina4(obj, obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4);
			break;
		case 2:
			cout << "Треугольник" << endl;
			cout << "Тип фигуры: ";
			cin >> obj.figure;
			cout << "x1 = ";
			cin >> obj.x1;
			cout << "y1 = ";
			cin >> obj.y1;
			cout << "x2 = ";
			cin >> obj.x2;
			cout << "y2 = ";
			cin >> obj.y2;
			cout << "x3 = ";
			cin >> obj.x3;
			cout << "y3 = ";
			cin >> obj.y3;
			//obj.x4 = obj.y4 = obj.x5 = obj.y5 = obj.R = obj.CD = obj.DE = obj.AE = obj.AD = 0;
			f.Build3(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, 13);
			f.dlina3(obj, obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3);
			break;
		case 3:
			cout << "Пятиугольник" << endl;
			cout << "Тип фигуры: ";
			cin >> obj.figure;
			cout << "x1 = ";
			cin >> obj.x1;
			cout << "y1 = ";
			cin >> obj.y1;
			cout << "x2 = ";
			cin >> obj.x2;
			cout << "y2 = ";
			cin >> obj.y2;
			cout << "x3 = ";
			cin >> obj.x3;
			cout << "y3 = ";
			cin >> obj.y3;
			cout << "x4 = ";
			cin >> obj.x4;
			cout << "y4 = ";
			cin >> obj.y4;
			cout << "x5 = ";
			cin >> obj.x5;
			cout << "y5 = ";
			cin >> obj.y5;
			//obj.R = obj.AC = obj.AD = 0;
			f.Build5(obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4, obj.x5, obj.y5, 13);
			f.dlina5(obj, obj.x1, obj.y1, obj.x2, obj.y2, obj.x3, obj.y3, obj.x4, obj.y4, obj.x5, obj.y5);
			break;
		case 4:
			cout << "Окружность" << endl;
			cout << "Введите тип фигуры: ";
			cin >> obj.figure;
			cout << "x1 = ";
			cin >> obj.x1;
			cout << "y1 = ";
			cin >> obj.y1;
			cout << "R = ";
			cin >> obj.R;
			//obj.x2 = obj.y2 = obj.x3 = obj.y3 = obj.x4 = obj.y4 = obj.x5 = obj.y5 = obj.AB = obj.BC = obj.CD = obj.DE = 0;
			//obj.AC = obj.AD = obj.AE = 0;
			f.Build0(obj.x1, obj.y1, obj.R, 13);
			obj.S = 3.14 * obj.R * obj.R;
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

void Flat::Build4(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, COLORREF color) {
	initwindow(700, 500); // инициализация окна 
	setcolor(13);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x4, y4, x1, y1);
	system("pause");
	closegraph(); // выход из графического режима
}
void Flat::Build3(int x1, int y1, int x2, int y2, int x3, int y3, COLORREF color) {
	initwindow(700, 500); // инициализация окна 
	setcolor(13);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	system("pause");
	closegraph(); // выход из графического режима
}
void Flat::Build5(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, COLORREF color) {
	initwindow(700, 500); // инициализация окна 
	setcolor(13);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x4, y4, x5, y5);
	line(x5, y5, x1, y1);
	system("pause");
	closegraph(); // выход из графического режима
}
void Flat::Build0(int x1, int y1, int R, COLORREF color) {
	initwindow(700, 500); // инициализация окна 
	setcolor(13);
	circle(x1, y1, R);
	system("pause");
	closegraph(); // выход из графического режима
}

void Flat::dlina3(Flat& obj, int x1, int y1, int x2, int y2, int x3, int y3) {
	obj.AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	obj.BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	obj.AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	double p;
	p = (obj.AB + obj.BC + obj.AC) / 2;
	obj.S = sqrt(p * (p - obj.AB) * (p - obj.BC) * (p - obj.AC));
	cout << "S = " << obj.S << endl;
}

void Flat::dlina4(Flat& obj, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	obj.AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	obj.BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	obj.CD = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
	obj.AD = sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1));
	double q = x1 * y2 + x2 * y3 + x3 * y4;
	double w = x2 * y1 + x3 * y2 + x4 * y3;
	obj.S = (q - w) / 2;
	cout << "S = " << obj.S << endl;
}

void Flat::dlina5(Flat& obj, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5) {
	obj.AB = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	obj.BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	obj.CD = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
	obj.DE = sqrt((x5 - x4) * (x5 - x4) + (y5 - y4) * (y5 - y4));
	obj.AE = sqrt((x5 - x1) * (x5 - x1) + (y5 - y1) * (y5 - y1));
	double q = x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5;
	double w = x2 * y1 + x3 * y2 + x4 * y3 + x5 * y4;
	obj.S = (q - w) / 2;
	cout << "S = " << obj.S << endl;
}