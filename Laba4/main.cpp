#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include "Stack.h"
#include "Stack_elem.h"
#include "Stack_char.h"
#include "Stack_elem_char.h"

using namespace std;

template <typename T>
void inversion_array(T* array, int size) //шаблонная функция инверсии массива
{
	int i = 0;
	cout << "Размер массива: ";
	cout << size << endl; //выводим размер массива
	T num;
	cout << "Заданный массив:" << endl;
	for (i = 0; i < size - 1; i++) //выводим массив
		cout << array[i] << " -> ";
	cout << array[i] << endl;
	cout << endl;

	cout << "Инвертированный массив:" << endl;
	for (i = 0; i < size / 2; i++)
	{
		num = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = num;
	}
	for (i = 0; i < size - 1; i++) //выводим массив
		cout << array[i] << " -> ";
	cout << array[i] << endl;
	cout << endl;
}

template <class T, typename TT>
void workwithstack(T* stptr, TT x)
{
	int choise, size, exit = 1;
	TT element;

	try
	{
		cout << "Введите размер стека:\n--> ";
		cin >> size;
		if (size <= 0)
			throw "Размер стека не может быть нулевым или отрицательным!";
		if (size > 30)
			throw "Размер стека больше 30 - это недопустимо!";
	}
	catch (const char* ex) { cout << ex << endl; }

	T st1(size);
	stptr = new T[1]; //в мэине мы объявили указатель на стек данного типа, здесь мы создали сам стек и задаем массив стеков с помощью объявленного указателя
	stptr[0] = st1; //в самую первую ячейку массива стека заносим только что объявленный стек
	T* sttmp = 0; //пригодится при создании новых стеков
	int num_of_stack = 0; //кол-во стеков
	int stacks = 1; //у нас всегда есть хотя бы один стек

	system("cls");

	while (exit == 1)
	{
		cout << "Доступно несколько операций. Выберете, что Вам необходимо: " << endl;
		cout << "1 - Добавить элемент к текущему стеку" << endl;
		cout << "2 - Удалить элемент из текущего стека" << endl;
		cout << "3 - Напечатать стек" << endl;
		cout << "4 - Создать новый стек" << endl;
		cout << "5 - Выбрать другой стек" << endl;
		cout << "6 - Сложение текущего стека" << endl;
		cout << "7 - Вычитание текущего стека" << endl;
		cout << "8 - Присовить текущий стек другому" << endl;
		cout << "9 - Сравнить текущий стек с другим" << endl;
		cout << "0 - Выйти к выбору задания" << endl;
		cout << "Вы используете стек № " << num_of_stack << endl;
		cin >> choise;

		system("cls");

		switch (choise)
		{
		case 1:
			cout << "Введите элемент стека: ";
			cin >> element;
			stptr[num_of_stack].push(element); //добавляем новый элемент
			system("pause");
			cout << "\n";
			break;
		case 2:
			try
			{
				if (!stptr[num_of_stack] == false)
					throw "Стек пуст, извлекать нечего!";
				stptr[num_of_stack].pop();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 3:
			cout << "Стек № " << num_of_stack << ": " << endl;
			stptr[num_of_stack].print();
			cout << "\n";
			system("pause");
			break;
		case 4:
			num_of_stack = stacks;
			sttmp = new T[stacks]; //создаем временный массив стеков размером с количество имеющихся стеков

			for (int i = 0; i < stacks; i++) //копируем все стеки во временный массив
				sttmp[i] = stptr[i];
			delete[] stptr;

			stptr = new T[++stacks]; //выделяем память в старом массиве стеков под новое количество стеков
			for (int i = 0; i < stacks - 1; i++) // копируем все стеки из временного массива стеков в старый массив стеков
				stptr[i] = sttmp[i];
			delete[] sttmp; // временный больше не нужен

			cout << "Введите размер нового стека: ";
			cin >> size;
			cout << "\n";

			for (int i = 0; i < size; i++)
				stptr[num_of_stack].push((130.0 + rand() % 56) / (2.0 + rand() % 2)); //заполняем случайными значениями

			cout << "Стек готов. Номер текущего стека: " << num_of_stack << endl;
			break;
		case 5:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				num_of_stack = choise;
				cout << "Переключение выполнено!" << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 6:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				stptr[num_of_stack] + stptr[choise];
				cout << "Операция сложения выполнена! Получившийся стек: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 7:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				stptr[num_of_stack] - stptr[choise];
				cout << "Операция вычитания выполнена! Получившийся стек: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 8:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				stptr[num_of_stack] = stptr[choise];
				cout << "Операция присвоения выполнена! Получившийся стек: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 9:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				if (stptr[num_of_stack] == stptr[choise])
					cout << "Текущий стек и выбраный равны!" << endl;
				else
					cout << "Текущий стек и выбраный неравны!" << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 0:
			delete[] stptr;
			exit = 0;
			break;
		}
	}
}

void workwithstack_char(Stack_char* stptr)
{
	int choise, size, exit = 1;
	char* val_ch = 0; //строка
	char* val_ch_tmp = 0; //временная строка
	int ind = 0;
	char ch = 0;

	try
	{
		cout << "Введите размер стека:\n--> ";
		cin >> size;
		if (size <= 0)
			throw "Размер стека не может быть нулевым или отрицательным!";
		if (size > 30)
			throw "Размер стека больше 30 - это недопустимо!";
	}
	catch (const char* ex) { cout << ex << endl; }

	Stack_char st1(size);
	stptr = new Stack_char[1]; //в мэине мы объявили указатель на стек данного типа, здесь мы создали сам стек и задаем массив стеков с помощью объявленного указателя
	stptr[0] = st1; //в самую первую ячейку массива стека заносим только что объявленный стек
	Stack_char* sttmp = 0; //пригодится при создании новых стеков
	int num_of_stack = 0; //кол-во стеков
	int stacks = 1; //у нас всегда есть хотя бы один стек

	system("cls");

	while (exit == 1)
	{
		cout << "Доступно несколько операций. Выберете, что Вам необходимо: " << endl;
		cout << "1 - Добавить элемент к текущему стеку" << endl;
		cout << "2 - Удалить элемент из текущего стека" << endl;
		cout << "3 - Напечатать стек" << endl;
		cout << "4 - Создать новый стек" << endl;
		cout << "5 - Выбрать другой стек" << endl;
		cout << "6 - Сложение текущего стека" << endl;
		cout << "7 - Вычитание текущего стека" << endl;
		cout << "8 - Присовить текущий стек другому" << endl;
		cout << "9 - Сравнить текущий стек с другим" << endl;
		cout << "0 - Выйти к выбору задания" << endl;
		cout << "Вы используете стек № " << num_of_stack << endl;
		cin >> choise;

		system("cls");

		switch (choise)
		{
		case 1:
			ind = 0;
			cout << "Введите элемент стека: ";

			cin.get(ch); //берем предыдущий символ
			cin.get(ch); //считываем новый символ
			val_ch = new char[1]; //выделяем память под символ конца стролки

			while (ch != '\n')
			{
				val_ch_tmp = new char[ind]; //выделяем память под текущее количество элементов
				for (int j = 0; j < ind; j++)
					val_ch_tmp[j] = val_ch[j];

				val_ch = new char[ind + 2]; //выделяем память под новый элемент плюс под \0

				for (int j = 0; j < ind; j++)
					val_ch[j] = val_ch_tmp[j];

				val_ch[ind] = ch;
				ind++;
				cin.get(ch);
			}
			val_ch[ind] = '\0';

			delete[] val_ch_tmp;
			stptr[num_of_stack].push(val_ch); // добавляем новый элемент
			system("pause");
			cout << "\n";
			break;
		case 2:
			try
			{
				if (!stptr[num_of_stack] == false)
					throw "Невозможно извлечь элемент из пустого стека";
				stptr[num_of_stack].pop();
			}
			catch (const char* ex)
			{
				cout << ex << endl;
			}

			system("pause");
			break;
		case 3:
			cout << "Стек № " << num_of_stack << ": " << endl;
			stptr[num_of_stack].print();
			cout << "\n";
			system("pause");
			break;
		case 4:
			num_of_stack = stacks;

			sttmp = new Stack_char[stacks]; 

			for (int i = 0; i < stacks; i++) 
				sttmp[i] = stptr[i];

			delete[] stptr;

			stptr = new Stack_char[++stacks]; 

			for (int i = 0; i < stacks - 1; i++)
				stptr[i] = sttmp[i];

			delete[] sttmp; // временный больше не нужен

			cout << "Введите размер нового стека: ";
			cin >> size;

			for (int i = 0; i < size; i++)
			{
				int size_str = (2 + rand() % 10);

				val_ch = new char[size_str];
				for (int j = 0; j < size_str; j++)
				{

					val_ch[j] = 65 + rand() % 56;
				}
				val_ch[size_str - 1] = '\0';
				stptr[num_of_stack].push(val_ch);
			}

			cout << "Стек готов. Номер текущего стека: " << num_of_stack << endl;
			break;
		case 5:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				num_of_stack = choise;
				cout << "Переключение выполнено!" << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 6:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				stptr[num_of_stack] + stptr[choise];
				cout << "Операция сложения выполнена! Получившийся стек: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 7:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				stptr[num_of_stack] - stptr[choise];
				cout << "Операция вычитания выполнена! Получившийся стек: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 8:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				stptr[num_of_stack] = stptr[choise];
				cout << "Операция присвоения выполнена! Получившийся стек: " << endl;
				stptr[num_of_stack].print();
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 9:
			try
			{
				if (stacks == 1)
					throw "Существует только один стек";

				cout << "Выберете стек (от 0 до " << stacks - 1 << ")" << endl;
				cin >> choise;
				if (choise == num_of_stack)
					throw "Вы не можете выбрать стек, с которым работаете!";
				system("cls");

				if ((choise < 0) || (choise == num_of_stack) || (choise >= stacks))
					throw "Некорректное значение. Переключение не выполнено";

				if ((stptr[num_of_stack] == stptr[choise]) == true)
					cout << "Текущий стек и выбраный равны!" << endl;
				else
					cout << "Текущий стек и выбраный неравны!" << endl;
			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 0:
			delete[] stptr;
			exit = 0;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int size_array;
	int size_stack;
	int choice, choice_type, exit = 1, exit1 = 1;
	srand(time(NULL));

	int* mass1 = 0;
	char* mass2 = 0;
	float* mass3 = 0;
	double* mass4 = 0;
	char** mass5 = 0;
	Stack<int>* stack1 = nullptr;
	int x1 = 0;
	Stack<float>* stack2 = nullptr;
	float x2 = 0;
	Stack<double>* stack3 = nullptr;
	double x3 = 0;
	Stack<char>* stack4 = nullptr;
	char x4 = 0;
	Stack_char* stack5 = nullptr;
	//char** x5 = 0;

	while (exit == 1)
	{
		cout << "Вас приветствует программа 4-ой лабораторной по ТП!";
		cout << "Выберите номер задания: " << endl;
		cout << "1 - Задание 1 - Инверсия массива\n2 - Задание 2 - Параметризированный стек\n0 - Выход\n-->" << endl;
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 1: /////////////////////////////////////////////////////////////////////////////////////////////////МАССИВ
			while (exit1 == 1)
			{
				cout << "Выберите желаемый тип данных массива: " << endl;
				cout << "1 - int\n2 - char\n3 - float\n4 - double\n5 - char*\n0 - Выход к выбору задания\n--> " << endl;
				cin >> choice_type;

				switch (choice_type)
				{
				case 1:
					size_array = 1 + rand() % 30; // размер массива
					mass1 = new int[size_array]; //выделяем память под массив размером с задданный рандомом

					for (int i = 0; i < size_array; i++) //заполняем массив
						mass1[i] = -30 + rand() % 60;

					inversion_array(mass1, size_array); //вызываем шаблонную функцию
					delete[] mass1;
					system("pause");
					system("cls");
					break;
				case 2:
					size_array = 1 + rand() % 30; // размер массива
					mass2 = new char[size_array]; //выделяем память под массив размером с задданный рандомом

					for (int i = 0; i < size_array; i++) //заполняем массив
						mass2[i] = 65 + rand() % 56; //mass2[i] = 0 + rand() % 30;

					inversion_array(mass2, size_array); //вызываем шаблонную функцию
					delete[] mass2;
					system("pause");
					system("cls");
					break;
				case 3:
					size_array = 1 + rand() % 30; // размер массива
					mass3 = new float[size_array]; //выделяем память под массив размером с задданный рандомом

					for (int i = 0; i < size_array; i++) //заполняем массив
						mass3[i] = (-60.0 + rand() % 119) / (2.0 + rand() % 2); //mass2[i] = 0 + rand() % 30;

					inversion_array(mass3, size_array); //вызываем шаблонную функцию
					delete[] mass3;
					system("pause");
					system("cls");
					break;
				case 4:
					size_array = 1 + rand() % 30; // размер массива
					mass4 = new double[size_array]; //выделяем память под массив размером с задданный рандомом

					for (int i = 0; i < size_array; i++) //заполняем массив
						mass4[i] = (-60.0 + rand() % 119) / (2.0 + rand() % 2); //mass2[i] = 0 + rand() % 30;

					inversion_array(mass4, size_array); //вызываем шаблонную функцию
					delete[] mass4;
					system("pause");
					system("cls");
					break;
				case 5:
					size_array = 1 + rand() % 30; //размер массива
					mass5 = new char* [size_array]; //массив случайных строк

					for (int i = 0; i < size_array; i++) //заполняем массив строк
					{
						int j = 0;
						int size_str = 2 + rand() % 30;
						mass5[i] = new char[size_str]; //строки
						for (j = 0; j < size_str; j++)
							mass5[i][j] = 65 + rand() % 56; //случайное значение строк
						mass5[i][--j] = '\0'; //символ конца строки
					}

					inversion_array(mass5, size_array);
					for (int i = 0; i < size_array; i++)
						delete[] mass5[i]; //удаляем строки
					delete[] mass5; //удаляем массив
					system("pause");
					system("cls");
					break;
				case 0:
					exit1 = 0;
					break;
				default:
					break;
				}
			}
			break;
		case 2: //////////////////////////СТЕК
			system("cls");

			cout << "Выберите желаемый тип данных массива: " << endl;
			cout << "1 - int\n2 - float\n3 - double\n4 - char\n5 - char*\n0 - Выход к выбору задания\n-->" << endl;
			cin >> choice_type;
			switch (choice_type)
			{
			case 1:
				workwithstack(stack1, x1);
				system("pause");
				system("cls");
				break;
			case 2:
				workwithstack(stack2, x2);
				system("pause");
				system("cls");
				break;
			case 3:
				workwithstack(stack3, x3);
				system("pause");
				system("cls");
				break;
			case 4:
				workwithstack(stack4, x4);
				system("pause");
				system("cls");
				break;
			case 5:
				workwithstack_char(stack5);
				system("pause");
				system("cls");
				break;
			case 0:
				break;
			default:
				break;
			}
			break;
		case 0:
			exit = 0;
			break;
		default:
			exit = 0;
			break;
		}
	}
	return 0;
}
