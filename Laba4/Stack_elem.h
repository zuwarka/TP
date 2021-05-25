#pragma once
#include <iostream>
#include <ctime>

template <typename T>
class Stack_elem //шаблон класса
{
private:
	T data = 0; //данные элемента стека
	Stack_elem<T>* next = 0; //указатель на следющий элемент стека
public:
	Stack_elem() : data(0) {};
	Stack_elem(T value) { data = value; };
	~Stack_elem() {};

	T get_data() { return data; };
	void set_data(T value) { data = value; };
	Stack_elem<T>*& get_next() { return next; };
	void set_next(Stack_elem<T>* new_next) { next = new_next; };

}; 
Файл Stack_char.h
#pragma once

//для char* создан отдельный класс, отдельный элемент, отдельеая функция

#include "Stack_elem_char.h"
using namespace std;

class Stack_char
{
private:
	Stack_elem_char* top_ch = 0;
	int size; // размер стека
protected:

public:
	Stack_char() : size(0) {};

	Stack_char(int size_st) : size(0)
	{
		for (int i = 0; i < size_st; i++)
		{
			int j;
			int str_size = 2 + rand() % 8;
			char* str = new char[str_size];
			for (j = 0; j < str_size; j++)
			{
				str[j] = 65 + rand() % 56;
			}
			str[--j] = '\0';
			this->push(str);
		}
	};

	~Stack_char() 
	{
		while (this->size > 0) //пока размер стэка больше нуля
		{
			if (top_ch == 0 || size == 0)
				break;
			this->pop();
		}
		system("cls");
	};

	void push(char* new_ch) // добавление элементов в конец стека
	{
		Stack_elem_char* new_elem = new(Stack_elem_char); //выделяем память под новый элемент
		new_elem->set_next(top_ch); 
		new_elem->set_data(new_ch);
		top_ch = new_elem; // последний элемент изменился
		size++; // добавили один элемент
	};

	void pop() // извлекаем последний(головной) элемент из стека
	{
		try
		{
			if (!this)
				throw "Стек пуст, удалять нечего!";

			char* deldata = 0; // извлеченный элемент
			deldata = top_ch->get_data(); //присваиваем значение последнего элемента 
			Stack_elem_char* temp = top_ch;
			if (top_ch == NULL)
				throw "Удалять нечего, стек и так пуст!";
			top_ch = top_ch->get_next();
			delete temp;
			temp = nullptr;
			size--;
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}

	void print() //вывод стека на экран
	{
		try
		{
			if (!this)
				throw "Стек пуст, выводить нечего.\n";

			Stack_elem_char* temp = top_ch;
			if (top_ch == 0)
				throw "Удалять нечего, стек и так пуст!";
			while (temp->get_next() != nullptr)
			{
				std::cout << temp->get_data() << " <-- ";
				temp = temp->get_next();
			}
			std::cout << temp->get_data() << std::endl;
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}

	Stack_char& operator = (const Stack_char& r) // перегрузка оператора присваивания
	{
		while (this->size > 0) //удаляем старые элементы
		{
			this->pop();
		}
		system("cls");

		char** buff = new char*[r.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
		Stack_elem_char* el_stack = r.top_ch; //новая переменная-вершина будущего стека

		for (int i = r.size - 1; i >= 0; i--)
		{	//пока счетчик не дойдет до конца стека
			if (el_stack == 0)
				break;
			buff[i] = el_stack->get_data(); //заносим в массив значения из стека
			el_stack = el_stack->get_next(); //ставим указатель на следующий элемент стека
		}

		for (int i = 0; i < r.size; i++)
			this->push(buff[i]); //вносим в новый стек значения из массива

		delete[] buff; //удаляем буфер
		return *this;
	}

	void operator + (Stack_char& Stack_tmp) // сложение двух стеков
	{
		if (size != Stack_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Сложение стеков невозможно" << endl;
		}
		else
		{
			int flag = 0;
			Stack_elem_char* current_top_tmp = top_ch; // указываем на конец текущего стека
			Stack_elem_char* current_top_tmp2 = Stack_tmp.top_ch; // и на конец второго
			int razm = 0;

			while (razm < size)
			{
				if (strlen(current_top_tmp->get_data()) != strlen(current_top_tmp2->get_data()))
				{
					flag = 1;
				}
				current_top_tmp = current_top_tmp->get_next(); // двигаем к началу текущую
				if (current_top_tmp == 0)
					break;
				current_top_tmp2 = current_top_tmp2->get_next(); // двигаем к началу вторую
				if (current_top_tmp == 0)
					break;
				razm++;
			}

			if (flag == 0)
			{
				Stack_elem_char* current_top_tmp = top_ch; // указываем на конец текущего стека
				Stack_elem_char* current_top_tmp2 = Stack_tmp.top_ch; // и на конец второго
				int i = 0;

				while (current_top_tmp->get_next() != 0) // пока не дойдем до первого элемента
				{
					int size_s = strlen(current_top_tmp->get_data());
					char* mas_str = new char[size_s + 1];
					for (i = 0; i < size_s; i++)
					{
						mas_str[i] = current_top_tmp->get_data()[i];
						mas_str[i] += current_top_tmp2->get_data()[i];
					}
					mas_str[i] = '\0';
					current_top_tmp->set_data(mas_str);

					current_top_tmp = current_top_tmp->get_next(); // двигаем к началу текущую
					if (current_top_tmp == 0)
						break;
					current_top_tmp2 = current_top_tmp2->get_next(); // двигаем к началу вторую
					if (current_top_tmp2 == 0)
						break;
				}

				int size_s = strlen(current_top_tmp->get_data());
				char* mas_str = new char[size_s + 1];
				for (i = 0; i < size_s; i++)
				{
					mas_str[i] = current_top_tmp->get_data()[i];
					mas_str[i] += current_top_tmp2->get_data()[i];
				}
				mas_str[i] = '\0';
				current_top_tmp->set_data(mas_str);
				cout << "Новый стек:" << endl; // выводим на экран
				this->print();
			}
			else
			{
				cout << "все строки должны быть одной длины" << endl; // выводим на экран
			}
		}
	}

	void operator - (Stack_char& Stack_tmp) // сложение двух стеков
	{
		if (size != Stack_tmp.size) // если размер не совпадает, дальше смотреть не будем
		{
			cout << "Сложение стеков невозможно" << endl;
		}
		else
		{
			int flag = 0;
			Stack_elem_char* current_top_tmp = top_ch; // указываем на конец текущего стека
			Stack_elem_char* current_top_tmp2 = Stack_tmp.top_ch; // и на конец второго
			int razm = 0;

			while (razm < size)
			{
				if (strlen(current_top_tmp->get_data()) != strlen(current_top_tmp2->get_data()))
				{
					flag = 1;
				}
				current_top_tmp = current_top_tmp->get_next(); // двигаем к началу текущую
				if (current_top_tmp == 0)
					break;
				current_top_tmp2 = current_top_tmp2->get_next(); // двигаем к началу вторую
				if (current_top_tmp == 0)
					break;
				razm++;
			}

			if (flag == 0)
			{
				Stack_elem_char* current_top_tmp = top_ch; // указываем на конец текущего стека
				Stack_elem_char* current_top_tmp2 = Stack_tmp.top_ch; // и на конец второго
				int i = 0;

				while (current_top_tmp->get_next() != 0) // пока не дойдем до первого элемента
				{
					int size_s = strlen(current_top_tmp->get_data());
					char* mas_str = new char[size_s + 1];
					for (i = 0; i < size_s; i++)
					{
						mas_str[i] = current_top_tmp->get_data()[i];
						mas_str[i] += current_top_tmp2->get_data()[i];
					}
					mas_str[i] = '\0';
					current_top_tmp->set_data(mas_str);

					current_top_tmp = current_top_tmp->get_next(); // двигаем к началу текущую
					if (current_top_tmp == 0)
						break;
					current_top_tmp2 = current_top_tmp2->get_next(); // двигаем к началу вторую
					if (current_top_tmp2 == 0)
						break;
				}

				int size_s = strlen(current_top_tmp->get_data());
				char* mas_str = new char[size_s + 1];
				for (i = 0; i < size_s; i++)
				{
					mas_str[i] = current_top_tmp->get_data()[i];
					mas_str[i] -= current_top_tmp2->get_data()[i];
				}
				mas_str[i] = '\0';
				current_top_tmp->set_data(mas_str);
				cout << "Новый стек:" << endl; // выводим на экран
				this->print();
			}
			else
			{
				cout << "все строки должны быть одной длины" << endl; // выводим на экран
			}
		}
	}

	bool operator == (const Stack_char& tmp_stack)
	{
		int x = 1;
		if (this->size != tmp_stack.size) //если не равен размер, то..
		{
			cout << "Стеки равны по размеру и по элементам" << endl;
			return false;
		}
		else // если размер равен, сравниваем поэлементно
		{
			Stack_elem_char* tmp_comprasion_1 = this->top_ch; //создаем переменную-указаетель и присваиваем ей указатель на послений в текущем стеке, который вызвал этот перегруженный оператор
			Stack_elem_char* tmp_comprasion_2 = tmp_stack.top_ch; // временный становится последним
			int i = size;
			do
			{
				int k = strlen(tmp_comprasion_1->get_data());
				for (int j = 0; j < k; j++)
				{
					if (tmp_comprasion_1->get_data()[i] == tmp_comprasion_2->get_data()[i])
					{
						continue;
					}
					else
					{
						cout << "Один из элементов стека не равен элементу другого стека" << endl;
						return false;
					}
				}
				i--;
				tmp_comprasion_1 = tmp_comprasion_1->get_next(); //двигаемся по элементам
				if (tmp_comprasion_1 == 0)
					break;
				tmp_comprasion_2 = tmp_comprasion_2->get_next();
				if (tmp_comprasion_2 == 0)
					break;
			} while (i != 0);
		}

		cout << "Стеки равны по размеру и по элементам" << endl;
		return true;
	}

	bool operator! () const
	{
		if (size == 0)
			return true;
		else
			return false;
	}; //проверка на пустоту
};
