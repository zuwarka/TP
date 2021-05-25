#pragma once
#include <iostream>
#include <ctime>

class Stack_elem_char 
{
private:
	char* data = 0; //данные элемента стека
	Stack_elem_char* next = 0; //указатель на следющий элемент стека
public:
	Stack_elem_char() : data(0) {};
	Stack_elem_char(char* value) { data = value; };
	~Stack_elem_char() {};

	char* get_data() { return data; };
	void set_data(char* value) { data = value; };
	Stack_elem_char*& get_next() { return next; };
	void set_next(Stack_elem_char* new_next) { next = new_next; };

}; 
