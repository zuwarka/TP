#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>
#include <string>
#include "Curve.h"
#include "Straight.h"
#include "Ellips.h"
#include "Hyperbola.h"

using namespace std;

/*Вариант 3 - Создать абстрактный класс "Кривые" для вычисления координаты у для некоторой х. 
Создать производные классы "Прямая", "Эллипс", "Гипербола" со своими функциями вычисления у в зависимости от входного параметра х*/

int main()
{
	setlocale(LC_ALL, "Rus");

	float x_str, k_str, b_str; //straight
	float x_ell, a_ell, b_ell; //ellips
	float x_hyp, k_hyp, b_hyp; //hyperbola
	string initfile = "C:\\Users\\polsk_000\\Desktop\\ГУАП\\2 курс\\ТП 4 семестр\\Лаба3-3\\data.txt";
	ifstream inFile;
	ofstream outFile;

	int c;
	cout << "Вас приветствует программа 3-ей лабораторной по ТП!" << endl;
	cout << "Как Вы хотите ввести данные?" << endl;
	cout << "1 - Вручную" << endl;
	cout << "2 - Из файла" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "--> ";
	cin >> c;
	
	switch (c)
	{
	case 1: //Вручную
		system("cls");
		cout << "Введите коэфициенты для прямой через пробел (x, k, b): ";
		cin >> x_str >> k_str >> b_str;
		cout << "Введите коэфициенты для эллипса через пробел (x, а, b): ";
		cin >> x_ell >> a_ell >> b_ell;
		if (a_ell == 0)
		{
			cout << "Значение А для эллипса не может быть нулевым, поэтому А будет равен единице" << endl;
			a_ell = 1;
		}
		if (b_ell == 0)
		{
			cout << "Значение B для эллипса не может быть нулевым, поэтому B будет равен единице" << endl;
			b_ell = 1;
		}
		cout << "Введите коэффициенты для гиперболы через пробел (x, k, b): ";
		cin >> x_hyp >> k_hyp >> b_hyp;
		if (x_hyp == 0)
		{
			cout << "Значение Х для гиперболы не может быть нулевым, поэтому Х будет равен единице" << endl;
			x_hyp = 1;
		}
		break;
	case 2:	
		system("cls");
		inFile.open(initfile);
		if (!inFile)
		{
			cout << "Ошибка открытия файла!" << endl;
			exit(1);
		}
		cout << "Порядок взятия данных через пробел: прямая, эллипс, гипербола" << endl;
		inFile >> x_str >> k_str >> b_str >> x_ell >> a_ell >> b_ell >> x_hyp >> k_hyp >> b_hyp;
		if (a_ell == 0.0)
		{
			cout << "Значение А для эллипса не может быть нулевым, поэтому А будет равен единице" << endl;
			a_ell = 1;
		}
		if (b_ell == 0.0)
		{
			cout << "Значение B для эллипса не может быть нулевым, поэтому B будет равен единице" << endl;
			b_ell = 1;
		}
		if (x_hyp == 0.0)
		{
			cout << "Значение Х для гиперболы не может быть нулевым, поэтому Х будет равен единице" << endl;
			x_hyp = 1;
		}
		cout << "Данные взяты!" << endl;
		inFile.close();
		break;	case 0:
		exit(0);
		break;
	default:
		break;
	}

	Curve* figures[3];
	Straight straight(x_str, k_str, b_str);
	Ellips ellips(x_ell, a_ell, b_ell);
	Hyperbola hyperbola(x_hyp, k_hyp, b_hyp);
	figures[0] = &straight;
	figures[1] = &ellips;
	figures[2] = &hyperbola;

	system("pause");
	system("cls");
	cout << "Координата Y прямой: " << figures[0]->findY() << ", при введенных Х = " << x_str << ", К = " << k_str << ", В = " << b_str << endl;
	cout << "Координата Y эллипса: " << figures[1]->findY() << ", при введенных Х = " << x_ell << ", А = " << a_ell << ", В = " << b_ell << endl;
	cout << "Координата Y гиперболы: " << figures[2]->findY() << ", при введенных Х = " << x_hyp << ", К = " << k_hyp << ", В = " << b_hyp << endl;

	system("pause");
	system("cls");

	cout << "Желаете перезаписать в файл новые данные?" << endl;
	cout << "1 - Да" << endl;
	cout << "2 - Нет" << endl;
	cout << "--> ";
	cin >> c;
	switch (c)
	{
	case 1:
		outFile.open(initfile);
		if (!outFile)
		{
			cout << "Ошибка открытия файла!" << endl;
			exit(1);
		}
		cout << "Введите через пробел новые данные: ";
		cin >> x_str >> k_str >> b_str >> x_ell >> a_ell >> b_ell >> x_hyp >> k_hyp >> b_hyp;
		outFile << x_str << " " << k_str << " " << b_str << " " << x_ell << " " << a_ell << " " << b_ell << " " << x_hyp << " " << k_hyp << " " << b_hyp;
		cout << "Данные записаны!" << endl;
		outFile.close();
		break;
	case 2: break;
	default: break;
	}

	return 0;
}
