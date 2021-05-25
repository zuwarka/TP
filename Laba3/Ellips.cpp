#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>
#include "Ellips.h"

using namespace std;

Ellips::Ellips() : x(1.0), y(0.0), a(1.0), b(1.0) {}
Ellips::~Ellips() {}

Ellips::Ellips(float x_var, float a_var, float b_var)
{
	a = a_var;
	b = b_var;
	x = x_var;
}

Ellips::Ellips(const Ellips& copy_ellips)
{
	x = copy_ellips.x;
	y = copy_ellips.y;
	a = copy_ellips.a;
	b = copy_ellips.b;
}

float Ellips::findY()
{
	float sqrt_num = (1 - x / a) * (1 + x / a);
	if (sqrt_num < 0)
		return y = -1;
	y = b * sqrt(sqrt_num);
	return y;
}
