#pragma once

class Real
{
private:
	float my_float;
public:
	Real();
	explicit Real(float value);
	~Real();
	Real(const Real& real_copy);

	Real operator- (const Real & r);
	Real& operator=(const Real& r); //перегружен для удобной работы
	void set_my_float(float& value);
	float get_my_float() const;

	friend bool operator< (const Real& l, const Real& r); //оператор сравнения, принимает два операнда, нет разницы в порядке, поэтому используем френд
	friend bool operator> (const Real& l, const Real& r); //аналогично выше
	friend bool operator== (const Real& l, const Real& r); //аналогично выше
	friend bool operator!= (const Real& l, const Real& r); //аналогично выше
	friend Real operator+ (const Real& l, const Real& r); //сложение, аналогично выше

	void out();
};
