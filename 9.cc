#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

// 200 b: 375 c:425
int main (int argc, char *const argv[]) {
	for (int b = 1; b <= 499; ++b) {
		double a_cand = (500000-1000*b)/(double)(1000-b);
		double c_cand = 1000-(a_cand+b);
		if (a_cand < b && b < c_cand && a_cand + b + c_cand == 1000) {
			int a_int = a_cand;
			int c_int = c_cand;
			if ( a_cand - a_int == 0 && c_cand - c_int == 0)
				//cout << "a_cand: " << a_cand  << " b: " << b << " c:" << c_cand << endl;
				cout << "prod: " << a_int * b * c_int << endl;
		}
	}
} 
