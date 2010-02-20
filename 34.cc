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

//145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
//Find the sum of all numbers which are equal to the sum of the factorial of their digits.

template <int N>
struct factorial{
	enum {value = N * factorial<N-1>::value };
};

template <>
struct factorial<0> {
	enum {value = 1 };
};

template <typename T>
bool check_fac(long nbr, const vector<T> & fac) {
	long origin = nbr;
	long sum = 0;
	do {
		int digit = nbr % 10;
		nbr = nbr / 10;
		sum += fac[digit];
	} while (nbr != 0);
	
	return sum == origin;
}

int	main (int argc, char *const argv[]) {	
	vector<int> fac;
	fac.reserve(9);
	fac.push_back(factorial<0>::value); fac.push_back(factorial<1>::value); fac.push_back(factorial<2>::value); fac.push_back(factorial<3>::value); 
	fac.push_back(factorial<4>::value); fac.push_back(factorial<5>::value); fac.push_back(factorial<6>::value); fac.push_back(factorial<7>::value); 
	fac.push_back(factorial<8>::value); fac.push_back(factorial<9>::value);
	
	int sum = 0;
	for (int i = 3; i <= 100000 ; ++i)
		if (check_fac(i, fac)) {
			sum += i;
			cout << i << endl;
		}
			cout << "sum: " << sum << endl;
}	