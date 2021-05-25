#pragma once

//abstract
class Curve
{
public:
	Curve() {};
	virtual ~Curve() {};
	virtual float findY() = 0;
};
