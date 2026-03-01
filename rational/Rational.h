#pragma once

class Rational {
private:
	void simplify();

public:
	int num;
	int den;
	Rational();
	Rational(int n);
	Rational(int n, int d);
	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r) const;
	Rational& operator-=(const Rational& r);
	Rational operator-(const Rational& r) const;
	Rational& operator *=(const Rational& r);
	Rational operator *(const Rational& r) const;
	Rational& operator /=(const Rational& r);
	Rational operator /(const Rational& r) const;
	double toDouble() const;  // преобразование в double

};
void KvUrav(const Rational& a, const Rational& b, const Rational& c);