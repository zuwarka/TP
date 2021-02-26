#pragma once
//using namespace std;

typedef struct Unit //элемент очереди
{
	int data = 0; //значение
	Unit* prev = 0; //указатель на предыдущи элемент
} Unit;

class parQueue
{
private:
	Unit* last = 0; //указатель на "конец" очереди

protected:
	int size; //размер очереди
	//Unit* get_last(); //объявление функции взятия конца очереди
	//int get_size(); //объявление функции взятия размера очереди

public:
	parQueue(); //конструктор без параметров
	~parQueue(); //деструктор

	Unit* get_last(); //объявление функции взятия конца очереди

	int pop(); //удаление элемента очереди
	void push(int el); //добавление элемента очереди
	void print(); //вывод на консоль очереди
	void merge(parQueue& Q1); //слияние двух очередей
	void copy(parQueue& Q); //копирование очереди
	bool isEmpty(); //проверка на заполненность

};
