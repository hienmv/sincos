
#include<iostream>
#include<cmath>
using namespace std;
/*
	Calculate sin, cos following the Taylor series
*/

const double EPOS = 3E-12;
const double MIN_VAL = 3E-14;

double doCalculate(double x, double val, int curVal, double fract, int sign) {
	while (true) 
	{
		fract *= (double)x*x / ((curVal + 1) * (curVal + 2));
		double newVal = val + sign * fract;
		if (fabs(newVal - val) <= EPOS) 
		{
			return (fabs(newVal) < MIN_VAL) ? 0.0 : newVal;
		}
		// update current value
		val = newVal;
		sign *= -1;
		curVal += 2;
	}
}

double calSinCpp(double x) {

	int div = round(x) / 360;
	x -= div * 360;
	x = x * M_PI / 180;

	double sinVal = x;
	int curVal = 1;
	double fract = x;
	int sign = -1;

	return doCalculate(x, sinVal, curVal, fract, sign);
}

double calCosCpp(double x) {

	int div = round(x) / 360;
	x -= div * 360;
	x = x * M_PI / 180;
	
	double cosVal = 1.0;
	int curVal = 0;
	double fract = 1.0;
	int sign = -1;

	return doCalculate(x, cosVal, curVal, fract, sign);
}
