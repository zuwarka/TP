#include "Stack.h"
#include "Real.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int stack_size = 0, value = 0; //переменные размера стека и вводимых данных
	int flag = 1, c; 

	///////////////////////////////////////////////////////ЗАДАНИЕ №1

	cout << "Вас приветствует программа 2-ой лабораторной по ТП!" << endl;
	cout << "Задание №1 - Унарные операции (стек)\nВведите размер стека: ";
	cin >> stack_size;
	system("cls");

	Stack st;
	cout << "Введите данные в стек: " << endl;
	for (int i = 0; i < stack_size; i++)
	{
		cin >> value;
		st.push(value);
	}
	system("cls");

	while (flag == 1)
	{
		cout << "Выберите, какие операции провести со стеком:" << endl;
		cout << "1 - Добавление нового элемента в стек" << endl;
		cout << "2 - Удаление элемента из стека" << endl;
		cout << "3 - Вывод стека на экран" << endl;
		cout << "4 - Префиксный оператор ++ (увеличение всех элементов на максимальный)" << endl;
		cout << "5 - Постфиксный оператор ++ (увеличение всех элементов на минимальный)" << endl;
		cout << "6 - Префиксный оператор -- (уменьшение всех элементов на максимальный)" << endl;
		cout << "7 - Постфиксный оператор -- (уменьшение всех элементов на минимальный)" << endl;
		cout << "0 - Переход ко втрому заданию работы" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: //1 - Добавление нового элемента в стек
			system("cls");
			cout << "Введите значение: " << endl;
			cin >> value;
			st.push(value);
			cout << "Значение добавлено в стек\n " << endl;
			break;
		case 2: //2 - Удаление элемента из стека
			if (!st)
			{
				cout << "Стек пуст, извлекать нечего.\n " << endl;
				break;
			}
			else
			{
				system("cls");
				value = st.pop();
				cout << "Извлеченный элемент: " << value << endl;
			}
			break;
		case 3: //3 - Вывод стека на экран
			if (!st)
			{
				cout << "Стек пуст, выводить нечего.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				st.print();
				cout << "\n";
			}
			break;
		case 4: //4 - Префиксный оператор ++ (увеличение всех элементов на максимальный)
			if (!st)
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				++st;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";

			}
			break;
		case 5: //5 - Постфиксный оператор ++ (увеличение всех элементов на минимальный)
			if (!st)
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				st++;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";

			}
			break;
		case 6: //6 - Префиксный оператор -- (уменьшение всех элементов на максимальный)
			if (!st)
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				--st;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";

			}
			break;
		case 7: //7 - Постфиксный оператор -- (уменьшение всех элементов на минимальный)
			if (!st)
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				st--;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 0: //0 - Выход
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}

	/////////////////////////////////////////////////////////ЗАДАНИЕ №2
	system("cls");

	float input_num1, input_num2;
	Real num1, num2, res(0.0);

	cout << "Задание №2 - Бинарные операторы\n" << endl;
	flag = 1;

	while (flag == 1)
	{
		cout << "Выберите, какие операции провести с классом вещественных чисел:" << endl;
		cout << "1 - Сложение" << endl;
		cout << "2 - Вычитание" << endl;
		cout << "3 - Сравнение \"меньше, чем\"" << endl;
		cout << "4 - Сравнение \"больше, чем\"" << endl;
		cout << "5 - Сравнение \"неравно\"" << endl;
		cout << "6 - Сравнение \"равно\"" << endl;
		cout << "0 - Выход" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: //1 - Сложение
			system("cls");
			cout << "Введите первое число: " << endl;
			cin >> input_num1;
			cout << "Введите второе число: " << endl;
			cin >> input_num2;
			num1.set_my_float(input_num1);
			num2.set_my_float(input_num2);
			res = num1 + num2;
			cout << "Результат: ";
			res.out();
			break;
		case 2: //2 - Вычитание
			system("cls");
			cout << "Введите первое число: " << endl;
			cin >> input_num1;
			cout << "Введите второе число: " << endl;
			cin >> input_num2;
			num1.set_my_float(input_num1);
			num2.set_my_float(input_num2);
			res = num1 - num2;
			cout << "Результат: ";
			res.out();
			break;
		case 3: //3 - Сравнение "меньше, чем"
			system("cls");
			cout << "Введите первое число: " << endl;
			cin >> input_num1;
			cout << "Введите второе число: " << endl;
			cin >> input_num2;
			num1.set_my_float(input_num1);
			num2.set_my_float(input_num2);
			if (num1 < num2)
				cout << "Первое число меньше, чем второе" << endl;
			else
				cout << "Первое число больше, чем второе" << endl;
			break;
		case 4: //4 - Сравнение "больше, чем"
			system("cls");
			cout << "Введите первое число: " << endl;
			cin >> input_num1;
			cout << "Введите второе число: " << endl;
			cin >> input_num2;
			num1.set_my_float(input_num1);
			num2.set_my_float(input_num2);
			if (num1 > num2)
				cout << "Первое число больше, чем второе" << endl;
			else
				cout << "Первое число меньше, чем второе" << endl;
			break;
		case 5: //5 - Сравнение "неравно"
			system("cls");
			cout << "Введите первое число: " << endl;
			cin >> input_num1;
			cout << "Введите второе число: " << endl;
			cin >> input_num2;
			num1.set_my_float(input_num1);
			num2.set_my_float(input_num2);
			if (num1 != num2)
				cout << "Первое число неравно второму" << endl;
			else
				cout << "Первое число равно второму" << endl;
			break;
		case 6: //6 - Сравнение "равно"
			system("cls");
			cout << "Введите первое число: " << endl;
			cin >> input_num1;
			cout << "Введите второе число: " << endl;
			cin >> input_num2;
			num1.set_my_float(input_num1);
			num2.set_my_float(input_num2);
			if (num1 == num2)
				cout << "Первое число равно второму" << endl;
			else
				cout << "Первое число неравно второму" << endl;
			break;
		case 0: //0 - Выход
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}

	return 0;
}
