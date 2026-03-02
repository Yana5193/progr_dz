#include <iostream>
#include "Rational.h"
using namespace std;
int main()
{
  
    void testArithmetic() {
        cout << "АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ " << endl;
        Rational a(1, 2);
        Rational b(1, 3);  
        Rational c(2, 3);
        Rational sum1 = a + b;
        cout << a << " + " << b << " = " << sum1 <<endl;
        Rational diff1 = a - b;
        cout << a << " - " << b << " = " << diff1 << endl;
        Rational prod1 = a * b;
        cout << a << " * " << b << " = " << prod1 << endl;
        Rational div1 = a / b;
        cout << a << " / " << b << " = " << div1 << endl;

    }
    void testAssignments() {
        cout << "СОСТАВНЫЕ ОПЕРАТОРЫ " << endl;
        Rational r1(1, 2);
        r1 += Rational(1, 3);
        cout << "r1 += 1/3 = " << r1 <<  << endl;
        
        Rational r2(3, 4);
        cout << "r2 = " << r2 << endl;
        r2 -= Rational(1, 4);
        cout << "r2 -= 1/4 = " << r2 << endl;

        Rational r3(2, 3);
        cout << "r3 = " << r3 << endl;
        r3 *= Rational(3, 4);
        cout << "r3 *= 3/4 = " << r3 << endl;

        Rational r4(1, 2);
        cout << "r4 = " << r4 << endl;
        r4 /= Rational(2, 3);
        cout << "r4 /= 2/3 = " << r4 << endl;

    }
    void testComparisons() {
        Rational r1(1, 2);  
        Rational r2(2, 4);  
        Rational r3(2, 3); 
        Rational r4(1, 3);  

        cout << "r1 = " << r1 << " (1/2)" << endl;
        cout << "r2 = " << r2 << " (2/4 -> 1/2)" << endl;
        cout << "r3 = " << r3 << " (2/3)" << endl;
        cout << "r4 = " << r4 << " (1/3)" << endl;

        cout << r1 << " == " << r2 << " : " << (r1 == r2 ? "true" : "false")<<endl;
        cout << r1 << " == " << r3 << " : " << (r1 == r3 ? "true" : "false")<<endl;

        cout << r1 << " != " << r2 << " : " << (r1 != r2 ? "true" : "false")<<endl;
        cout << r1 << " != " << r3 << " : " << (r1 != r3 ? "true" : "false")<<endl;

        cout << r4 << " < " << r1 << " : " << (r4 < r1 ? "true" : "false")<<endl;
        cout << r3 << " < " << r1 << " : " << (r3 < r1 ? "true" : "false")<<endl;

        cout << r4 << " <= " << r1 << " : " << (r4 <= r1 ? "true" : "false")<<endl;
        cout << r1 << " <= " << r2 << " : " << (r1 <= r2 ? "true" : "false")<<endl;
        cout << r3 << " <= " << r1 << " : " << (r3 <= r1 ? "true" : "false")<<endl;

        cout << r3 << " > " << r1 << " : " << (r3 > r1 ? "true" : "false")<<endl;
        cout << r4 << " > " << r1 << " : " << (r4 > r1 ? "true" : "false")<<endl;

        cout << r3 << " >= " << r1 << " : " << (r3 >= r1 ? "true" : "false")<<endl;
        cout << r1 << " >= " << r2 << " : " << (r1 >= r2 ? "true" : "false")<<endl;
        cout << r4 << " >= " << r1 << " : " << (r4 >= r1 ? "true" : "false")<<endl;
    }
    void testKvUrav() {
        cout << "KvUrav()<< endl;

        cout << "Тест 1: два рациональных корня " << endl;
        cout << "Уравнение: x^2 - 3x + 2 = 0 (корни 1 и 2)" << endl;
        KvUrav(Rational(1), Rational(-3), Rational(2));

        cout << "Тест 2: один корень" << endl;
        cout << "Уравнение: x^2 - 2x + 1 = 0 (корень 1)" << endl;
        KvUrav(Rational(1), Rational(-2), Rational(1));

        cout << " Тест 3: нет корней" << endl;
        cout << "Уравнение: x^2 + x + 1 = 0" << endl;
        KvUrav(Rational(1), Rational(1), Rational(1));

    }
    

}

