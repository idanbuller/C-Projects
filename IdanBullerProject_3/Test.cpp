#include <iostream>
#include "polynomial.h"
#include "Rational.h"
#include <iomanip>
// Einav Pincu - 315113175
using namespace std;
ostream& operator<<(std::ostream& out, const Polynomial& p) {
	int temp = p.getDegree(true),i;
	out << "Polynomial = " << p.getCell(0);
	if(temp>1){
		for (i = 1; i <= temp + 1; i++) {
			if (i == temp + 1) {
				if (p.getCell(i) == 0)
					break;
			}
			out << " + ";
			out << setprecision(2) << p.getCell(i) << "X^" << i;
		}
	}
	out << endl;
	return out;
}
ostream& operator<<(std::ostream& out, const Rational& r) {
	Polynomial p1 = r.getNom();
	Polynomial p2 = r.getDenom();
	int temp = p1.getDegree(true);
	out << "Polynomial = " << p1.getCell(0);
	int i;
	if (temp > 1) {
		for (i = 1; i <= temp + 1; i++) {
			if (i == temp + 1) {
				if (p1.getCell(i) == 0)
					break;
			}
			out << " + ";
			out << setprecision(2) << p1.getCell(i) << "X^" << i;
		}
	}
	out << endl;
	out << "------------" << endl;
	temp = p2.getDegree(true);
	out << "Polynomial = " << p2.getCell(0);
	if (temp > 1) {
		for (i = 1; i <= temp + 1; i++) {
			if (i == temp + 1) {
				if (p2.getCell(i) == 0)
					break;
			}
			out << " + ";
			out << setprecision(2) << p2.getCell(i) << "X^" << i;
		}
	}
	out << endl;
	return out;
}
void testPolynomial()
{
	cout << "----- start testPolynomial ---------" << endl;
	cout << "test0 :" << Polynomial::getMaxDegree() << endl;
	Polynomial p1;
	cout << "test1: " << p1;
	Polynomial p2(6);
	p2.setCoeff(2, 0.4);
	cout << "test2: " << p2 << "degree=" << p2.getDegree(false) << endl;
	double c[5] = { 0.1, 0.2, 0 ,11.5, 1.3 };
	Polynomial p3(c, 4);
	cout << "test3: " << p3;
	p2.setCoeff(2, 0.0);
	cout << "test4: " << p2;
	cout << "test6 :maxDegree = " << Polynomial::getMaxDegree() << endl;
	cout << "______________" << endl;
}
void testRational() {
	cout << "----- start testRational ---------" << endl;
	cout << "test7" << endl;
	Rational r1;
	r1.print();
	cout << r1;
	double c[] = { 0,2,2,3,4,5 };
	Polynomial p1(c, 5);
	c[0] = 1.2;
	Polynomial p2(c, 3);
	Rational r2(p1, p2);
	cout << "test8" << endl;
	r2.print();
	cout << endl << r2 << endl;
	cout << "test9" << endl;
	cout << "nom = " << r2.getNom();
	cout << "denom = " << r2.getDenom();

	cout << "test10 :maxDegree = " << Polynomial::getMaxDegree() << endl;
	cout << "__________________________" << endl;
}

int main()
{
	testPolynomial();
	testRational();
}
