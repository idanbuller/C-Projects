#define _CRT_SECURE_NO_WARNINGS
#include "Polynomial.h"
#include <iostream>
#include <iomanip>
using namespace std;
int Polynomial::maxDeg = 0;

Polynomial::Polynomial()
{
	this->arr = new double[1];
	this->arr[0] = 0;
}

Polynomial::Polynomial(int degree) : deg(degree) {
	this->arr = new double[degree + 1];
	for (int i = 0; i <= degree; i++) {
		this->arr[i] = 0;
	}
	int temp = Polynomial::getMaxDegree();
	int temp2 = Polynomial::getDegree(true);
	if (temp < temp2)
		maxDeg = temp2;
}
Polynomial::Polynomial(double* array, int degree) : deg(degree) {
	this->arr = new double[degree + 1];
	for (int i = 0; i <= degree; i++) {
		if (array[i] != NULL) {
			this->arr[i] = array[i];
		}
		else
			this->arr[i] = 0;
	}
	int temp = Polynomial::getMaxDegree();
	if (temp < degree)
		maxDeg = degree;

}
Polynomial::~Polynomial() {
	//cout << "destructor was acivated for polynomal with degree: " << getDegree(false) << endl;
	delete[] arr;
}
void Polynomial::setCoeff(int index, double num) {
	this->arr[index] = num;
}
int Polynomial::getDegree(bool flage) const {
	int i = 0;
	if (!flage || deg == 0) {
		return deg;
	}
	else {
		for (i = deg - 1; i >= 0; i--) {
			if (this->arr[i] != 0)
				return i;
		}
	}
	return i;
}
int Polynomial::getMaxDegree() {
	return Polynomial::maxDeg;
}
void Polynomial::print() {
	int temp = Polynomial::getDegree(true);
	cout << "Polynomial = " << this->arr[0];
	int i;
	if (temp > 1) {
		for (i = 1; i <= temp + 1; i++) {
			if (i == temp + 1) {
				if (this->arr[i] == 0)
					break;
			}
			cout << " + ";
			cout << setprecision(2) << this->arr[i] << "X^" << i;
		}
	}
	cout << endl;


}
double Polynomial::getCell(int i) const {
	return this->arr[i];
}

Polynomial::Polynomial(const Polynomial& p) : deg(p.getDegree(false))
{
	int temp = p.getDegree(false);
	this->arr = new double[temp + 1];
	for (int i = 0; i <= temp+1; i++)
		this->arr[i] = p.getCell(i);
}