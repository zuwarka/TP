#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>
#include "Hyperbola.h"

using namespace std;

Hyperbola::Hyperbola() : x(1.0), y(0.0), k(1.0), b(0.0) {}
Hyperbola::~Hyperbola() {}

Hyperbola::Hyperbola(float x_var, float k_var, float b_var)
{
	x = x_var;
	k = k_var;
	b = b_var;
}

Hyperbola::Hyperbola(const Hyperbola& copy_hyper)
{
	x = copy_hyper.x;
	y = copy_hyper.y;
	k = copy_hyper.k;
	b = copy_hyper.b;
}

float Hyperbola::findY()
{
	y = k / x + b;
	return y;
}
