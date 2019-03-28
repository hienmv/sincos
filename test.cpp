// for test shared library
#include<iostream>
#include "sincos.h"
#include "sincosCpp.hpp"
using namespace std;

enum Version {CPP = 1, C = 2};
enum Type {SIN = 1, COS = 2};

int main(void) {
	cout << "Test sin cos calculation" << endl;
	while (true)
	{
		cout << "*****************" << endl;
		cout << "Format input: A B C" << endl;
		cout << "A: 1 - C++ version,  2 - C version" << endl;
		cout << "B: 1 - sin calculation, 2 - cos calculation" << endl;
		cout << "C: the parameter to calculate (90, 120..)" << endl;
		cout << "Please input:" << endl;	
		int version, type, val;
		cin >> version >> type >> val;
		if (version == CPP) {
			if (type == SIN) {
				cout << calSinCpp(val) << endl; 
			} 
			else if (type == COS) {
				cout << calCosCpp(val) << endl;
			}	
		}	
		else if (version == C) {
			if (type == SIN) {
				cout << calSin(val) << endl;
			} 
			else if (type == COS) {
				cout << calCos(val) << endl;
			}
		}
	
		cout << "Do you want to continue ? Y/y to continue, other to exit " << endl;
		string yesStr;
		cin >> yesStr;
		if (yesStr.compare("Y") && yesStr.compare("y")) {
			break;
		}
	}
	
return 0;
}

