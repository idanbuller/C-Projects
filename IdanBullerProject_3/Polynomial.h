#pragma once
using namespace std;


class Polynomial {
public:
	Polynomial();
	Polynomial(int degree);
	Polynomial(double* array, int degree);
	~Polynomial();
	void setCoeff(int index, double num);
	int getDegree(bool flag) const;
	static int getMaxDegree();
	void print();
	double getCell(int i) const;
	Polynomial(const Polynomial& p);


private:
	const int deg = 0;
	double* arr;
	static int maxDeg;
};