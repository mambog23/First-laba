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
	bool flag = true; // ��� �������� ���������� ������� (���� ���������), ��� ����������� - ��� � ����
	while (flag) {
		system("cls"); // ���� �����, ����� ���� ������� �� ���������
		cout << "����: " << endl << endl;
		cout << "1 - 2D" << endl;
		cout << "2 - 3D" << endl;
		cout << "0 - ����� �� ���������" << endl << endl;
		cout << "�������� �����: ";
		cin >> button;
		if (cin.fail()) { // �������� �� ���������� ����
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			menu(flat, "flat.txt"); // ����� ���� (flat)
			break;
		case 2:
			menu(volume, "volume.txt"); // ����� ���� (volume)
			break;
		case 0:
			flag = false; // ����� �� ���������
			cout << "\n�����" << endl;
			break;
		default:
			cout << endl << "������������ ������, ������� ������!" << endl
				<< endl; // �������� �� ���������� ����
			system("pause");
			break;
		}
	}
	return 0;
}