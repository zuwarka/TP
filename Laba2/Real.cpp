#include <iostream>
#include <locale>
#include "Real.h"

using namespace std;

/*КОНСТРУКТОРЫ*/

Real::Real() : my_float(0.0) {}
Real::Real(float value)
{
	my_float = value;
}
Real::~Real() {}
Real::Real(const Real& real_copy)
{
	this->my_float = real_copy.my_float;
}

/*МЕТОДЫ*/

bool operator< (const Real& l, const Real& r) { return l.my_float < r.my_float; }
bool operator> (const Real& l, const Real& r) { return l.my_float > r.my_float; }
bool operator== (const Real& l, const Real& r) { return l.my_float == r.my_float; }
bool operator!= (const Real& l, const Real& r) { return l.my_float != r.my_float; }
Real operator+ (const Real& l, const Real& r) { return Real(l.my_float + r.my_float); }

Real Real::operator- (const Real& r) { return Real(this->my_float - r.my_float); }
Real& Real::operator= (const Real& r) 
{
	if (this == &r) //проерка на самоприсваивание
		return *this;
	my_float = r.my_float;
	return *this;
}

void Real::set_my_float(float& value) { my_float = value; }
float Real::get_my_float() const { return my_float; }

void Real::out() { cout << my_float << endl; }
