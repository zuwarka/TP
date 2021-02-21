#include <iostream>
#include "stack.h"

using namespace std;

Unit* Stack::get_head()
{
	return head;
}

int Stack::get_size()
{
	return size;
}

void Stack::set_size(int& s)
{
	size = s;
}

Stack::Stack()
{
	head = 0;
	size = 0;
}

Stack::Stack(const Stack& st_copy)
{

}

Stack::Stack(int size_init)
{
	this->size = size_init;
	head = 0;
}

Stack::~Stack()
{
	while (size > 0)
	{
		Unit* temp = head;
		head = temp->next;
		delete temp;
		size--;
	}
}

void Stack::push(int el)
{
	Unit* new_unit = new Unit;
	new_unit->data = el;

	if (size == 0) //если мы инициализируем стек, то выделенная память на элемент становится головой стека
	{
		new_unit->next = nullptr; //
		head = new_unit; //
		size++;
	}
	else //иначе - у нас есть как миниум один элемент в стеке
	{
		new_unit->next = head; //указатель на следующий элемент указывает на голову
		head = new_unit; //головой стал новый элемент
		size++;
	}
}

int Stack::pop()
{
	Unit* tmp = head;
	int deldata = 0;


}
