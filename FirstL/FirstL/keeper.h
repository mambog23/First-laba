#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;

template <class T>
class Keeper {
	T* ptr;
	int size;
public:
	Keeper();
	~Keeper();
	void push(); // Функция добавления нового объекта
	void pop(int); // Функция удаления объекта
	void write(string); // Функция записи объекта в файл
	void read(string); // Функция считывания объекта из файла
	void show(); // Функция вывода объекта на экран
	void edit(int); // Функция редактирования объекта



	void Build(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, COLORREF color);
};

template<class T>
Keeper<T>::Keeper() { // Конструктор
	cout << "Вызов конструктора по умолчанию для класса Keeper" << endl << endl;
	ptr = nullptr;
	size = 0;
}

template<class T>
Keeper<T>::~Keeper() { // Деструктор
	cout << "Вызов деструктора для класса Keeper" << endl << endl;
	delete[] ptr;
}

template<class T>
void Keeper<T>::read(string s) { // Функция считывания объекта из файла
	delete[] ptr;
	ifstream fin(s, ios::in);
	fin >> size;
	ptr = new T[size];
	for (int i = 0; i < size; ++i) {
		fin >> ptr[i];
	}
	fin.close();
	cout << "Прочитано успешно" << endl << endl;
}

template<class T>
void Keeper<T>::write(string s) { // Функция записи объекта в файл
	ofstream fout(s, ios::out);
	try {
		if (size == 0) {
			exception error("Пусто");
			throw error;
		}
		fout << size << endl;
		for (int i = 0; i < size; ++i) {
			fout << ptr[i] << endl;
		}
		fout.close();
		cout << "Запись прошла успешно" << endl << endl;
	}
	catch (exception& error) {
		cout << error.what() << endl;
	}
}

template<class T>
void Keeper<T>::edit(int change) { // Функция редактирования объекта
	try {
		if (size == 0) {
			exception error("Пусто");
			throw error;
		}
		if (change < 0 || change >= size) {
			exception bug("Неверный номер");
			throw bug;
		}
		cin >> ptr[change];
	}
	catch (exception& bug) {
		cout << bug.what() << endl << endl;
	}
}

template < class T>
void Keeper<T>::pop(int num) { // Функция удаления объекта
	try {
		if (size == 0) {
			exception error("Пусто");
			throw error;
		}
		if (num < 0 || num >= size) {
			exception bug("Неверный номер");
			throw bug;
		}
		T* temp = new T[size - 1];
		ptr[num] = ptr[size - 1];
		for (int i = 0; i < size - 1; ++i) {
			temp[i] = ptr[i];
		}
		delete[] ptr;
		ptr = temp;
		--size;
		cout << endl << endl << "Объект добавлен" << endl << endl;
	}
	catch (exception& error) {
		cout << error.what() << endl << endl;
	}
}

template<class T>
void Keeper<T>::push() { // Функция добавления нового объекта
	T* temp = new T[size + 1];
	for (int i = 0; i < size; ++i) {
		temp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = temp;
	cin >> ptr[size];
	++size;
	cout << endl << endl << "Новый объект добавлен" << endl << endl;
}

template<class T>
void Keeper<T>::show() { // Функция вывода объекта на экран
	setlocale(LC_ALL, "Russian");


	if (size == 0) {
		cout << "Пусто" << endl << endl;
	}
	else {
		for (int i = 0; i < size; ++i) {
			cout << ptr[i] << endl;
		}
	}
}