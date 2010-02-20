#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <utility>	//for std::make_pair
#include <boost/lambda/lambda.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>
#include <gmpxx.h>		//for c++

using namespace std;
using namespace NTL;
using namespace boost;

// g++ -I/usr/local/include -I/usr/local/include/boost-1_33_1 -I/usr/local/include/gmp-4.2.1 -L/usr/local/lib 27.cc -o main -lntl -lm -lgmpxx -lgmp

// 49/98 = 4/8
// 54/67
// 30/50 = 3/5

bool check(double num, double den) {
	string n = lexical_cast<string>(num);
	string d = lexical_cast<string>(den);
	if (d.find('0') != string::npos || n.find('0') != string::npos)		// num or den contains a zero, abort
		return false;
	
	if (n.find(d[0]) == string::npos && n.find(d[1]) == string::npos)	//no common digit
		return false;
	
	if (n[0] == d[0]) {
		double new_n = lexical_cast<double>(n[1]);
		double new_d = lexical_cast<double>(d[1]);
		return new_n/new_d == num/den;
	}
	else if (n[0] == d[1]) {
		double new_n = lexical_cast<double>(n[1]);
		double new_d = lexical_cast<double>(d[0]);
		return new_n/new_d == num/den;
	}
	else if (n[1] == d[0]) {
		double new_n = lexical_cast<double>(n[0]);
		double new_d = lexical_cast<double>(d[1]);
		return new_n/new_d == num/den;
	}
	else if (n[1] == d[1]) {
		double new_n = lexical_cast<double>(n[0]);
		double new_d = lexical_cast<double>(d[0]);
		return new_n/new_d == num/den;
	}
	
		return false;
}
int	main (int argc, char *const argv[]) {	
	//if (check(49, 90))
	//	cout << "non-trivial example";
	

	for (int num = 10; num <= 98; ++num)
		for (int den = num+1; den <=99; ++den)
			if (check(num, den))
				cout << num << " / " << den << endl;
 
}	