#include "Rational.h"
#include <iostream>
#include <cmath>
using namespace std;

Rational::Rational() {
	num = 0;
	den = 1;
}
Rational::Rational(int n) {
	num = n;
	den = 1;
}
Rational::Rational(int n, int d) {
	num = n;
	den = d;
}
void Rational::simplify() {
	if (den < 0) {
		num = -num;
		den = -den;
	}
	int del = gcd(num, den);
	if (del > 1) {
		num /= del;
		den /= del;
	}
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
bool Rational::operator==(const Rational& r) const {
	int leftNum = num * r.den;
	int rightNum = r.num * den;
	return (leftNum == rightNum);
}
bool Rational::operator!=(const Rational& r) const {
	return !(*this == r);
}
bool Rational::operator<(const Rational& r) const {
	int leftNum = num * r.den;
	int rightNum = r.num * den;
	return (leftNum < rightNum);
}
bool Rational::operator<=(const Rational& r) const {
	return (*this < r || *this == r);
}
bool Rational::operator>(const Rational& r) const {
	int leftNum = num * r.den;
	int rightNum = r.num * den;
	return (leftNum > rightNum);
}
bool Rational::operator>=(const Rational& r) const {
	return (*this > r || *this == r);
}
bool isPerfectSquare(int n) {
	if (n < 0) return false;
	int root = (int)sqrt(n);
	return root * root == n;
}
void KvUrav(const Rational& a, const Rational& b, const Rational& c) {
	setlocale(LC_ALL, "Russian");
	Rational D = b * b - Rational(4) * a * c;
	if (D < Rational(0)) {
		cout << "Нет корней" << endl;
	}
	else if (D == Rational(0)) {
		Rational x = Rational(0) - b / (Rational(2) * a);
		cout << "x = " << x << endl;
	}
	else {
		if (isPerfectSquare(D.num) && isPerfectSquare(D.den)) {
			int sqrtNum = (int)sqrt(D.num);
			int sqrtDen = (int)sqrt(D.den);
			Rational sqrtD(sqrtNum, sqrtDen);

			Rational x1 = (Rational(0) - b + sqrtD) / (Rational(2) * a);
			Rational x2 = (Rational(0) - b - sqrtD) / (Rational(2) * a);

			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
		else {
			cout << "Корни иррациональны" << endl;
		}
	}
	}
}
