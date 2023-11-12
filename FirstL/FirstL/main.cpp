#include <iostream>
#include "volume.h"
#include "menu.h"
#include "keeper.h"
#include "figures.h"
#include "flat.h"


#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	//Keeper <Figures> figures;

	Keeper <Flat> flat;
	Keeper <Volume> volume;



	int button;
	bool flag = true; // Для проверки логических условий (флаг состояний), как выключатель - ВКЛ и ВЫКЛ
	while (flag) {
		system("cls"); // Ждет ввода, чтобы окно консоли не закрылось
		cout << "Меню: " << endl << endl;
		cout << "1 - 2D" << endl;
		cout << "2 - 3D" << endl;
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
			menu(flat, "flat.txt"); // Вызов меню (flat)
			break;
		case 2:
			menu(volume, "volume.txt"); // Вызов меню (volume)
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
	}
	return 0;
}