#include "Rational.h"
#include <iostream>
#include <cmath>
Rational::Rational() {
	num = 0;
	den = 1;
}
Rational::Rational(int n) {
	num = n;
	den = 1;
}
Rational::Rational(int n,int d) {
	num = n;
	den = d;
}
void Rational::simplify() {


}
Rational& Rational::operator+=(const Rational& r) {
	num = num * r.den + den * r.num;
	den = den * r.den;
	simplify();
	return (*this);
}
Rational Rational::operator+(const Rational& r) const {
	Rational R(*this);
	return R += r;
}
Rational& Rational::operator-=(const Rational& r) {
	num = num * r.den - den * r.num;
	den = den * r.den;
	simplify();
	return *this;
}
Rational Rational::operator-(const Rational& r) const {
	Rational result(*this);
	return result -= r;
}
Rational& Rational::operator*=(const Rational& r) {
	num *= r.num;
	den *= r.den;
	simplify();
	return *this;
}
Rational Rational::operator*(const Rational& r) const {
	return Rational(num * r.num, den * r.den);
}
Rational& Rational::operator/=(const Rational& r) {
	num *= r.den;
	den *= r.num;
	simplify();
	return *this;
}
Rational Rational::operator/(const Rational& r) const {
	return Rational(num * r.den, den * r.num);
}
double Rational::toDouble() const {
	return static_cast<double>(num) / den;
}
void KvUrav(const Rational& a, const Rational& b, const Rational& c) {
	double a2 = a.toDouble();
	double b2 = b.toDouble();
	double c2 = c.toDouble();
	double D = b2 * b2 - 4 * a2 * c2;
	if (D < 0) {
		cout << "Нет корней";
	}
	else if (D == 0) {
		cout << "Существует один корень";
		double x = -b2 / (2 * a2);
	}
	else {
		double sqrtD = sqrt(D);
		double x1 = (-b2 + sqrtD) / (2 * a2);
		double x2 = (-b2 - sqrtD) / (2 * a2);
		cout << "Два корня:";
		cout << "x1 = " << x1;
		cout << "x2 = " << x2;
	}
}
