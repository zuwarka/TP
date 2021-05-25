#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>
#include "Straight.h"

using namespace std;

Straight::Straight() : x(0.0), y(0.0), k(1.0), b(0.0) {}
Straight::~Straight() {}

Straight::Straight(float x_var, float k_var, float b_var)
{
	x = x_var;
	k = k_var;
	b = b_var;
}

Straight::Straight(const Straight& copy_straight)
{
	x = copy_straight.x;
	y = copy_straight.y;
	k = copy_straight.k;
	b = copy_straight.b;
}

float Straight::findY()
{
	y = k * x + b;
	return y;
}
