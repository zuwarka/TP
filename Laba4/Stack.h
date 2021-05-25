#pragma once
#include <iostream>
#include "Stack_elem.h"

template <typename T>
class Stack //шаблон класса
{
private:
	Stack_elem<T>* top = 0; //вершина стека
	int size; //размер
public:
	//конструкторы
	Stack() : size(0) {}; //конструктор без параметров (исп. список инициализации); 

	Stack(int size_st) : size(0)
	{ 
		for (int i = 0; i < size_st; i++)
			this->push((130.0 + rand() % 56) / (2.0 + rand() % 2));
	}; //конструктор с параметрами (задаем размер стека и рандомные значегния в него)

	~Stack() 
	{ 
		while (this->size > 0) 
		{ 
			if (top == 0 || size == 0)
				break;
			this->pop(); 
		} 
		system("cls"); 
	}; //деструктор

	Stack(const Stack<T>& st_copy) //конструктор копирования
	{
		T* buff = new T[st_copy.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
		Stack_elem<T>* el_stack = st_copy.top; //новая переменная-вершина будущего стека

		for (int i = 0; i <= st_copy.size - 1; i++)
		{	//пока счетчик не дойдет до конца стека
			if (el_stack == NULL)
				break;
			buff[i] = el_stack->get_data(); //заносим в массив значения из стека
			el_stack = el_stack->get_next(); //ставим указатель на следующий элемент стека
		}

		for (int i = 0; i < st_copy.size; i++)
			this->push(buff[i]); //вносим в новый стек значения из массива

		delete[] buff; //удаляем буфер
	}

	//функции стека
	void push(T value)
	{
		Stack_elem<T>* new_elem = new(Stack_elem<T>); //инициализируем новый юнит стека и выделяем под него память
		new_elem->set_next(top); //теперь новый юнит стал вершиной
		new_elem->set_data(value);
		top = new_elem; //и вершина указывает на новый юнит
		size++;
	}; //добавление элемента в стек

	void pop()
	{
		try
		{
			if (!this)
				throw "Стек пуст, удалять нечего!";

			T deldata = 0; // извлеченный элемент
			deldata = top->get_data(); //присваиваем значение последнего элемента 
			Stack_elem<T>* temp = top;
			if (top == NULL)
				throw "Удалять нечего, стек и так пуст!";
			top = top->get_next();
			delete temp;
			temp = nullptr;
			size--;
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}; //извлечение вершины

	void print()
	{
		try
		{
			if (!this)
				throw "Стек пуст, выводить нечего.\n";

			Stack_elem<T>* temp = top;
			if (top == 0)
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
	}; //вывод стека на экран

	//геттеры и сеттеры
	int get_size() const //взять размер стека
	{
		return size;
	};

	bool operator! () const
	{
		if (size == 0)
			return true;
		else
			return false;
	}; //проверка на пустоту

	bool operator== (const Stack& r)
	{
		if (this->size != r.size)
		{
			std::cout << "Стеки неравны, так как их размер разный" << std::endl;
			return false;
		}
		else
		{
			int i = size; //счетик равный размеру
			Stack_elem<T>* tmp_cmp = this->top; //временный элемент левого операнда
			Stack_elem<T>* tmp_cmp_r = r.top; //временный элемент правого операнда
			while (i != 0)
			{
				if (tmp_cmp->get_data() == tmp_cmp_r->get_data())
					i--;
				else
				{
					std::cout << "Один из элементов стека не равен элементу другого стека" << std::endl;
					return false;
				}
				tmp_cmp = tmp_cmp->get_next();
				if (tmp_cmp == 0)
					break;
				tmp_cmp_r = tmp_cmp_r->get_next();
				if (tmp_cmp_r == 0)
					break;
			}

			std::cout << "Стеки равны по размеру и по элементам" << std::endl;
			return true;
		}
	}; //сравнение двух стеков по размеру

	Stack& operator= (const Stack& r)
	{
		while (this->size > 0) //удаляем старые элементы
		{
			this->pop();
		}
		system("cls");

		T* buff = new T[r.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
		Stack_elem<T>* el_stack = r.top; //новая переменная-вершина будущего стека

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
	}; //присваивание двух стеков

	void operator+ (Stack<T>& r)
	{
		if (this->size != r.size)
			std::cout << "Сложить два стека невозможно, так как их размеры неравны!" << std::endl;

		T* buff_l = new T[this->size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
		Stack_elem<T>* el_stack_l = this->top; //новая переменная-вершина будущего стека

		for (int i = this->size - 1; i >= 0; i--)
		{	//пока счетчик не дойдет до конца стека
			if (el_stack_l == 0)
				break;
			buff_l[i] = el_stack_l->get_data(); //заносим в массив значения из стека
			el_stack_l = el_stack_l->get_next(); //ставим указатель на следующий элемент стека
		}

		T* buff_r = new T[r.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
		Stack_elem<T>* el_stack_r = r.top; //новая переменная-вершина будущего стека

		for (int i = r.size - 1; i >= 0; i--)
		{	//пока счетчик не дойдет до конца стека
			if (el_stack_r == 0)
				break;
			buff_r[i] = el_stack_r->get_data(); //заносим в массив значения из стека
			el_stack_r = el_stack_r->get_next(); //ставим указатель на следующий элемент стека
		}

		while (this->size > 0) //удаляем старые элементы
		{
			this->pop();
		}
		system("cls");

		for (int i = 0; i < r.size; i++) //складываем значения, присваивая их в левый операнд и заносим в левый опернад-стек
		{
			buff_l[i] += buff_r[i];
			this->push(buff_l[i]);
		}

		delete[] buff_l; //удаляем буфер
		delete[] buff_r;
	}; //сложение двух стеков

	void operator- (Stack<T>& r)
	{
		if (this->size != r.size)
			std::cout << "Сложить два стека невозможно, так как их размеры неравны!" << std::endl;

		T* buff_l = new T[this->size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
		Stack_elem<T>* el_stack_l = this->top; //новая переменная-вершина будущего стека

		for (int i = this->size - 1; i >= 0; i--)
		{	//пока счетчик не дойдет до конца стека
			if (el_stack_l == 0)
				break;
			buff_l[i] = el_stack_l->get_data(); //заносим в массив значения из стека
			el_stack_l = el_stack_l->get_next(); //ставим указатель на следующий элемент стека
		}

		T* buff_r = new T[r.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
		Stack_elem<T>* el_stack_r = r.top; //новая переменная-вершина будущего стека

		for (int i = r.size - 1; i >= 0; i--)
		{	//пока счетчик не дойдет до конца стека
			if (el_stack_r == 0)
				break;
			buff_r[i] = el_stack_r->get_data(); //заносим в массив значения из стека
			el_stack_r = el_stack_r->get_next(); //ставим указатель на следующий элемент стека
		}

		while (this->size > 0) //удаляем старые элементы
		{
			this->pop();
		}
		system("cls");

		for (int i = 0; i < r.size; i++) //вычитаем значения, присваивая их в левый операнд и заносим в левый опернад-стек
		{
			buff_l[i] -= buff_r[i];
			this->push(buff_l[i]);
		}

		delete[] buff_l; //удаляем буфер
		delete[] buff_r;
	}; //вычитание двух стеков
}; 
