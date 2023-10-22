#pragma once
#include "keeper.h"
#include "figures.h"
#include "flat.h"
#include <iostream>
using namespace std;

template <typename T> // T - ���, ��������� � ��������� �������
void menu(T& obj, string line) {
	int c;
	int i;
	bool flag = true;
	setlocale(LC_ALL, "Russian");
	while (flag) {
		system("cls");
		cout << "�������� ��������: " << endl << endl;
		cout << "1 - �������� ������" << endl;
		cout << "2 - ������� ������" << endl;
		cout << "3 - ����� �� �����" << endl;
		cout << "4 - �������� ������" << endl;
		cout << "5 - ��������� � ����" << endl;
		cout << "6 - ����� �� �����" << endl;
		cout << "0 - �����" << endl << endl;
		cout << "�������� ��������: ";
		cin >> c;
		if (cin.fail() || c < 0 || c > 7) { // �������� �� ���������� ����
			c = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		system("cls");
		switch (c) {
		case 1:
			obj.push(); // ���������� �������
			system("pause");
			break;
		case 2: obj.show();
			cout << "�������� ��� ��������: ";
			cin >> i;
			obj.pop(i); // �������� �������
			system("pause");
			break;
		case 3:
			obj.show(); // ����� ������� �� �����
			system("pause");
			break;
		case 4:
			obj.show();
			cout << "�������� ��� ���������: ";
			cin >> i;
			obj.edit(i); // �������������� �������
			system("pause");
			break;
		case 5:
			obj.write(line); // ������ ������� � ����
			system("pause");
			break;
		case 6:
			obj.read(line); // ���������� ������� �� �����
			system("pause");
			break;
		case 0:
			flag = false; // �����
			break;
		default:
			cout << "������� �� 1 �� 7:" << endl << endl;
			system("pause");
			break;
		}
	}
}