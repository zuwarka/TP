#include <iostream>
#include "Queue1.h"
using namespace std;

int sonQueue_private::function19()
{
	Unit* last = get_last();
	int max = get_last()->data;
	int min = get_last()->data;
	int result = 0;
	int delta = 0;

	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last != nullptr)
		{
			if (last->data > max)
				max = last->data;
			if (last->data < min)
				min = last->data;
			last = last->prev;
		}

		delta = max - min;
		last = get_last();

		while (last != nullptr)
		{
			if (last->data > delta)
			{
				result = last->data;
				break;
			}
			last = last->prev;
		}
	}
	return result;
}
int sonQueue_private::pop() { return parQueue::pop(); }
void sonQueue_private::push(int el) { return parQueue::push(el); }
void sonQueue_private::print() { return parQueue::print(); }
void sonQueue_private::merge(sonQueue_private& Q1, sonQueue_private& Q2) { return parQueue::merge(Q1, Q2); }
void sonQueue_private::copy(sonQueue_private& Q1) { return parQueue::copy(Q1); }
bool sonQueue_private::isEmpty() { return parQueue::isEmpty(); }

int sonQueue_protected::function19()
{
	Unit* last = get_last();
	int max = get_last()->data;
	int min = get_last()->data;
	int result = 0;
	int delta = 0;
	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last != nullptr)
		{
			if (last->data > max)
				max = last->data;
			if (last->data < min)
				min = last->data;
			last = last->prev;
		}

		delta = max - min;
		last = get_last();

		while (last != nullptr)
		{
			if (last->data > delta)
			{
				result = last->data;
				break;
			}
			last = last->prev;
		}
	}
	return result;
}
int sonQueue_protected::pop() { return parQueue::pop(); }
void sonQueue_protected::push(int el) { return parQueue::push(el); }
void sonQueue_protected::print() { return parQueue::print(); }
void sonQueue_protected::merge(sonQueue_protected& Q1, sonQueue_protected& Q2) { return parQueue::merge(Q1, Q2); }
void sonQueue_protected::copy(sonQueue_protected& Q1) { return parQueue::copy(Q1); }
bool sonQueue_protected::isEmpty() { return parQueue::isEmpty(); }

int sonQueue_public::function19()
{
	Unit* last = get_last();
	int max = get_last()->data;
	int min = get_last()->data;
	int result = 0;
	int delta = 0;
	if (size == 0)
	{
		cout << "Очередь пуста!" << endl;
	}
	else
	{
		while (last != nullptr)
		{
			if (last->data > max)
				max = last->data;
			if (last->data < min)
				min = last->data;
			last = last->prev;
		}

		delta = max - min;
		last = get_last();

		while (last != nullptr)
		{
			if (last->data > delta)
			{
				result = last->data;
				break;
			}
			last = last->prev;
		}
	}
	return result;
}
