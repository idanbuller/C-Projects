#include "Rational.h"
#include <iostream>
using namespace std;

Rational::Rational() {
	static Polynomial p1;
	static Polynomial p2;
	p2.setCoeff(0, 1);
	this->up = &p1;
	this->down = &p2;
}

Rational::Rational(Polynomial p1, Polynomial p2) {
	static Polynomial p3(p1);
	static Polynomial p4(p2);
	this->up = &p3;
	this->down = &p4;
	if (p2.getCell(0)==0) {
		int temp = p2.getDegree(true);
		int i,flag=0;
		for (i = 1; i <= temp; i++) {
			if (p2.getCell(i) != 0) {
				this->down = &p2;
				flag = 1;
				break;
			}
			
		}
		if (flag == 0)
		{
			Polynomial p3;
			p3.setCoeff(0, 1);
			this->down = &p3;
		}
	}
}
Rational::~Rational() {}
void Rational::print() {
	up->print();
	cout << "------------" << endl;
	down->print();
}
Polynomial Rational::getDenom()const {
	return *this->down;
}
Polynomial Rational::getNom()const {
	return *this->up;
}
