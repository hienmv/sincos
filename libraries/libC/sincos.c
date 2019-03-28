
#include<stdio.h>
#include<math.h>
/*
	Calculate sin, cos following the Taylor series
*/

const double EPOS = 3E-12;
const double MIN_VAL = 3E-14;

double calSin(double x) {

	int div = round(x) / 360;
	x -= div * 360;
	x = x * M_PI / 180;

	double sinVal = x;
	int curVal = 1;
	double fract = x;
	int sign = -1;

	while (1) 
	{
		fract *= (double)x*x / ((curVal + 1) * (curVal + 2));
		double newSinVal = sinVal + sign * fract;
		if (fabs(newSinVal - sinVal) <= EPOS) 
		{
			return (fabs(newSinVal) < MIN_VAL) ? 0.0 : newSinVal;
		}
		// update current value
		sinVal = newSinVal;
		sign *= -1;
		curVal += 2;
	}
	return 0.0;
}

double calCos(double x) {

	int div = round(x) / 360;
	x -= div * 360;
	x = x * M_PI / 180;
	
	double cosVal = 1.0;
	int curVal = 0;
	double fract = 1.0;
	int sign = -1;
	
	while (1) 
	{
		fract *= (double)x*x / ((curVal+1) * (curVal+2));
		double newCosVal = cosVal + sign * fract;
		if (fabs(newCosVal - cosVal) <= EPOS) 
		{
			return (fabs(newCosVal) < MIN_VAL) ? 0.0 : newCosVal;
		}
		// update current value;
		cosVal = newCosVal;
		sign *= -1;
		curVal += 2;
	}

	return 0.0;
}
