#pragma once
#include "Polynomial.h"
class Rational {
public:
	Rational();
	Rational(Polynomial p1,Polynomial p2);
	~Rational();
	void print();
	Polynomial getDenom()const;
	Polynomial getNom()const;

private:
	Polynomial *up;
	Polynomial *down;
};