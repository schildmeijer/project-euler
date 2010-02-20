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
#include <utility>	//for std::make_pair
#include <boost/lambda/lambda.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>
//#include <gmp.h>		//for c
#include <gmpxx.h>		//for c++

using namespace std;
using namespace NTL;
using namespace boost;

// g++ -I/usr/local/include -I/usr/local/include/boost-1_33_1 -I/usr/local/include/gmp-4.2.1 -L/usr/local/lib 27.cc -o main -lntl -lm -lgmpxx -lgmp

// 1634 = 1^4 + 6^4 + 3^4 + 4^4
// 8208 = 8^4 + 2^4 + 0^4 + 8^4
// 9474 = 9^4 + 4^4 + 7^4 + 4^4
// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

bool check(int nbr) {
	int origin = nbr;
	int sum = 0;
	do {
		double digit = nbr%10;
		nbr = nbr/10;
		sum += pow(digit, 5);
	} while (nbr != 0);
	
	return sum == origin;
	
}
int	main (int argc, char *const argv[]) {	
	int sum = 0;
	for (int i = 2; i < 200000; ++i)
		if(check(i))
			sum += i;
	
	cout << sum << endl;
}	