#pragma once
#include "Queue.h"

class sonQueue_private : private parQueue
{
public:
	int function19();
	int pop(); //удаление элемента очереди
	void push(int el); //добавление элемента очереди
	void print(); //вывод на консоль очереди
	void merge(sonQueue_private& Q1); //слияние двух очередей
	void copy(sonQueue_private& Q); //копирование очереди
	bool isEmpty(); //проверка на заполненность
};

class sonQueue_protected : protected parQueue
{
public:
	int function19();
	int pop(); //удаление элемента очереди
	void push(int el); //добавление элемента очереди
	void print(); //вывод на консоль очереди
	void merge(sonQueue_protected& Q1); //слияние двух очередей
	void copy(sonQueue_protected& Q); //копирование очереди
	bool isEmpty(); //проверка на заполненность
};

class sonQueue_public : public parQueue
{
public:
	int function19();
};
