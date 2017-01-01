// polynomial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>

class poly {
public:
	poly(const int&, const double*);
	double value(const double&);
	~poly();

private:
	double* a;
	int n;
};

poly::poly(const int& power, const double* b) {
	n = power;
	std::cout << "Highest power = " << n-1 << std::endl;
	a = new double[n];
	for (size_t i = 0; i < n; i++) {
		a[i] = b[i];
		std::cout << "a(" << i << ") = " << a[i] << std::endl;
	}
	std::cout << std::endl;
}

double poly::value(const double& x0) {
	std::cout << "Value to evaluate at = " << x0 << std::endl;
	double val = 0.0;
	for (size_t i = 1; i < n; i++) {
		val += a[i] * (pow(x0, i));
	}
	val += a[0];
	return val;
}

poly::~poly() {
	delete[] a;
}



int main()
{
	int powp1 = 5;
	double* coefp1 = new double[powp1];
	coefp1[0] = 3.0; coefp1[1] = -1.2; coefp1[2] = 1.5; coefp1[3] = -3.0; coefp1[4] = 3.0;
	poly p1(powp1, coefp1);
	double x0 = 4 * atan(1.0);
	std::cout << "Value of p(" << x0 << ") = " << p1.value(x0) << std::endl;	
	
	
    return 0;
}

