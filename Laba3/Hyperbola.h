#pragma once
#include "Curve.h"

//y=k/x+b
class Hyperbola : public Curve
{
private:
	float x;
	float y = 0.0;
	float k;
	float b;
public:
	Hyperbola();
	Hyperbola(float x_var, float k_var = 1.0, float b_var = 0);
	Hyperbola(const Hyperbola& copy_hyper);
	virtual ~Hyperbola();

	virtual float findY(); //virtual здеь необязательна, но так мы помним, что функция - виртуальная
};
