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

// n² + an + b, where |a| < 1000 and |b| < 1000
// Find the product of the coefficients, a and b, for the quadratic expression 
// that produces the maximum number of primes for consecutive values of n, starting with n = 0.

vector<int> primes;

// returns the number of primes for consecutive n. n=1,2,3...
int check_formula(int a, int b) {
	int n = -1;
	int candidate = 0;
	do {
		++n;
		candidate = n*n + a*n + b;
	} while(binary_search(primes.begin(), primes.end(), candidate));
	return n;
}

int	main (int argc, char *const argv[]) {	
	PrimeSeq ps;
	for (int i = 1; i <= 500000; ++i)
		primes.push_back(ps.next());
	
	int max = 0;
	for (int a = -999; a <=999; ++a) {
		for (int b = -999; b <=999; ++b) {
			int cand = check_formula(a,b);
			if (cand > max) {
				max = cand;
				cout << "prod:" << a*b << endl;
 			}
		}
	}
	cout << max << endl;
} 