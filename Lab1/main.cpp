#include <iostream>
#include <locale>
#include "Queue.h"
#include "Queue1.h"

using namespace std;

/*19 - Нахождение первого элемента, большего размаха (разности между максимальным и минимальным элементами)*/

template <class T>
void chosen_class(T* q, int n_q) //шаблонная функция для дальнейшей работы с классом
{
	setlocale(LC_ALL, "Rus");
	int c;
	int flag = 1;
	int value; //введенное значение пользователем
	int index = 0; //номер очереди, с которой работаем
	int count = 1; //кол-во очередей, с которыми работает пользователь
	int res4 = 0; //переменная для выполнения пункта задания
	int chosen_q; //номер выбранной очереди

	while (flag == 1)
	{
		cout << "1 - Добавление элемента очереди" << endl;
		cout << "2 - Извлечение элемента очереди" << endl;
		cout << "3 - Вывод очереди на экран" << endl;
		cout << "4 - Нахождение элемента большего размаха" << endl;
		cout << "5 - Создание копии очереди" << endl;
		cout << "6 - Слияние двух очередей" << endl;
		cout << "7 - Выбор иной очереди" << endl;
		cout << "8 - С какой очередью я сейчас работаю?" << endl;
		cout << "0 - Вернуться к выбору класса-наследника" << endl;
		cout << "-> ";
		cin >> c;

		switch (c)
		{
		case 1: //добавление элемента очереди
			system("cls");
			cout << "Введите значение: ";
			cin >> value;
			q[index].push(value);
			cout << "Значение добавлено в очередь.\n " << endl;
			break;
		case 2: //извлечение элемента очереди
			if(q[index].isEmpty()) 
			{
				cout << "Очередь уже пуста, извлекать нечего.\n " << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				value = q[index].pop();
				cout << "Извлеченный элемент: " << value << endl;
				cout << "\n";
			}
			break;
		case 3: //вывод очереди на экран
			if (q[index].isEmpty())
			{
				cout << "Очередь пуста, выводить нечего.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				q[index].print();
				cout << "\n";
			}
			break;
		case 4: //нахождение элемента большего размаха
			if (q[index].isEmpty())
			{
				cout << "Очередь пуста, задание выполнить невозможно.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				res4 = q[index].function19();
				cout << "Первый элемент, который больше размаха: " << res4 << endl;
				cout << "\n";
			}
			break;
		case 5: //создание копии очереди
			if (q[index].isEmpty())
			{
				cout << "Очередь пуста, копировать нечего.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				if (count == n_q)
				{
					cout << "Невозможно создать копию очереди, так как количество очередей достигло максимума.\n" << endl;
					system("pause");
					break;
				}

				system("cls");
				q[count].copy(q[index]);
				cout << "Очередь успешно скопирована. Теперь существует две равных очереди.\n" << endl;
				count++; //теперь у нас есть как миниум две очереди с индексами 0 и 1...
			}
			break;
		case 6: //слияние двух очередей
			if (count == 1)
			{
				cout << "Существует только одна очередь.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "С какой очередью произвести слияние?" << endl;
				cin >> chosen_q;

				if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index))
				{
					cout << "Некорректное значение!\n" << endl;
					system("pause");
					break;
				}

				if (q[chosen_q].isEmpty())
				{
					cout << "Невозможно произвести слияние, так как вторая очередь пуста.\n" << endl;
					system("pause");
					break;
				}
				
				system("cls");
				q[index].merge(q[chosen_q]);
				//count++; //теперь существует как миниум три очереди с индексами 0, 1, 2...
				cout << "\n";
			}
			break;
		case 7: //выбор иной очереди
			system("cls");
			cout << "Сейчас вы работаете с очередью №" << index << endl;
			cout << "Введите номер очереди (от 0 до " << n_q - 1 << ") , на которую хотите переключиться: ";
			cin >> chosen_q;

			if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index))
			{
				cout << "Некорректное значение или количество очередей превышено!\n" << endl;
				system("pause");
			}
			else
			{
				index = chosen_q;
				count++;
				system("cls");
				cout << "Вы переключились на очередь №" << index << endl;
				cout << "\n";
			}
			break;
		case 8:
			system("cls");
			cout << "Вы сейчас работаете с очередью №" << index << endl;
			cout << "\n";
			break;
		case 0:
			cout << "\n";	
			flag = 0;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	//int choose_class; //переменные выбора класса очереди
	int num_q; //переменная количества очередей
	int c;
	int flag = 1;

	sonQueue_private* q1 = NULL;
	sonQueue_protected* q2 = NULL;
	sonQueue_public* q3 = NULL;

	cout << "Вас приветсвует консольная программа 1-ой лабораторной по ТП!" << endl;
	cout << "Введите колчество очередей: ";
	cin >> num_q;
	system("cls");

	cout << "Выберите, с каким классом-наследником Вы будете работать: " << endl;

	while (flag == 1)
	{
		cout << "1 - Приватный" << endl;
		cout << "2 - Защищенный" << endl;
		cout << "3 - Публичный" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "-> ";
		cin >> c;

		switch (c)
		{
		case 1:
			q1 = new sonQueue_private[num_q];
			system("cls");
			chosen_class(q1, num_q);
			delete[] q1;
			break;
		case 2:
			q2 = new sonQueue_protected[num_q];
			system("cls");
			chosen_class(q2, num_q);
			delete[] q2;
			break;
		case 3:
			q3 = new sonQueue_public[num_q];
			system("cls");
			chosen_class(q3, num_q);
			delete[] q3;
			break;
		case 0:
			flag = 0;
			break;
		default:
			system("cls");
			cout << "Некорректный ввод!" << endl;
			break;
		}
	}

	return 0;
}
