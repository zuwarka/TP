#pragma once
#include "Curve.h"

//y=kx+b
class Straight : public Curve
{
private:
	float y = 0.0;
	float x;
	float k;
	float b;
public:
	Straight();
	Straight(float x_var, float k_var = 1.0, float b_var = 0.0);
	Straight(const Straight& copy_straight);
	virtual ~Straight();

	virtual float findY(); //virtual здеь необязательна, но так мы помним, что функция - виртуальная
};
