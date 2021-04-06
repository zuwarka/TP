#include "Stack.h"
#include <iostream>
#include <locale>

using namespace std;

/* КОНСТРУКТОРЫ */

Stack::Stack() : top(0), size(0) {} //конструктор без параметров (исп. список инициализации)

Stack::Stack(int size_st) : top(0)//конструктор с параметром, задает размер и инициализирует элемент
{
	this->size = size_st; //вызванному объекту устанавливаем размер
}

Stack::~Stack()
{
	if ((top == 0) || (size == 0))
	{
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
	else
	{
		while (top->next != 0) //пока не дойдем до нулевого указателя
		{
			Unit* temp = top; //временная переменная юнита, присваиваем ей значение вершины
			top = temp->next; //теперь вершина указывает на следующий за ней элемент,
			delete temp; //а временную - удаляеям
		}
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
}

Stack::Stack(const Stack& Stack_copy) : size(Stack_copy.size)
{
	int* buff = new int[Stack_copy.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
	Unit* el_stack = Stack_copy.top; //новая переменная-вершина будущего стека

	for (int i = 0; i <= Stack_copy.size - 1; i++)
	{	//пока счетчик не дойдет до конца стека
		buff[i] = el_stack->data; //заносим в массив значения из стека
		el_stack = el_stack->next; //ставим указатель на следующий элемент стека
	}

	for (int i = 0; i < Stack_copy.size; i++)
		this->push(buff[i]); //вносим в новый стек значения из массива

	delete[] buff; //удаляем буфер
}

/* МЕТОДЫ КЛАССА СТЕКА */

void Stack::push(int value)
{
	Unit* new_unit = new Unit; //инициализируем новый юнит стека и выделяем под него память
	new_unit->next = top; //теперь новый юнит стал вершиной
	top = new_unit; //и вершина указывает на новый юнит
	top->data = value; //вносим значение в вершину
	size++;
}

int Stack::pop()
{
	setlocale(LC_ALL, "Rus");

	if (!this)
	{
		cout << "Стек пуст, удалять нечего." << endl;
	}

	Unit* temp = top; //временная переменная-вершина 
	int deldata = 0; //место под удаленный элемент

	deldata = top->data; //присваиваем значение удаляемого элемента
	top = top->next; //вершина теперь тот юнит, который был под вершиной
	delete temp; //удаляем переменную-вершину
	size--;
	return deldata; //вернули удаленный элемент
}

void Stack::print()
{
	if (size == 0)
	{
		cout << "Стек пуст, выводить нечего." << endl;
	}
	else
	{
		Unit* temp = top;
		while (temp->next != nullptr)
		{
			cout << temp->data << " <-- ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
}

Unit* Stack::get_top()
{
	return top;
}

int Stack::get_size() const
{
	return size;
}

int Stack::set_size(int& value)
{
	size = value;
}

bool Stack::operator! () const
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Stack& Stack::operator --()
{
	Unit* tmp = top;
	int max = tmp->data;

	if (size == 0)
	{
		cout << "Стек пуст, невозможно провести операцию!" << endl;
	}
	else //ищем максимальный элемент
	{
		while (tmp != nullptr)
		{
			if (tmp->data > max)
				max = tmp->data;
			tmp = tmp->next;
		}
	}

	int len = size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop();
	for (int i = len - 1; i >= 0; i--)
		this->push(buff[i] - max); //в обратном порядке (как было до преобразования) заносим новые значения в стек

	delete[] buff;
	return *this; //возвращаем сам объект, который вызвал фугкцию
}

Stack& Stack::operator --(int)
{
	Unit* tmp = top;
	int min = tmp->data;

	if (size == 0)
	{
		cout << "Стек пуст, невозможно провести операцию!" << endl;
	}
	else //ищем минимальный элемент
	{
		while (tmp != nullptr)
		{
			if (tmp->data < min)
				min = tmp->data;
			tmp = tmp->next;
		}
	}

	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		this->push(buff[i] - min); //в обратном порядке (как было до преобразования) заносим новые значения в стек

	delete[] buff;
	return *this;
}

void operator++ (Stack& St)
{
	Unit* tmp = St.top;
	int max = tmp->data;

	if (St.size == 0)
	{
		cout << "Стек пуст, невозможно провести операцию!" << endl;
	}
	else //ищем максимальный элемент
	{
		while (tmp != nullptr)
		{
			if (tmp->data > max)
				max = tmp->data;
			tmp = tmp->next;
		}
	}

	tmp = St.top;
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] + max); //в обратном порядке (как было до преобразования) заносим новые значения в стек

	delete[] buff;
}

void operator ++(Stack& St, int)
{
	Unit* tmp = St.top;
	int min = tmp->data;

	if (St.size == 0)
	{
		cout << "Стек пуст, невозможно провести операцию!" << endl;
	}
	else //ищем максимальный элемент
	{
		while (tmp != nullptr)
		{
			if (tmp->data < min)
				min = tmp->data;
			tmp = tmp->next;
		}
	}

	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] + min); //в обратном порядке (как было до преобразования) заносим новые значения в стек

	delete[] buff;
}
