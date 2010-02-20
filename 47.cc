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
#include <boost/algorithm/string.hpp>
#include <gmpxx.h>			//for c++

using namespace std;
using namespace NTL;
using namespace boost;

// The first two consecutive numbers to have two distinct prime factors are:
// 14 = 2 7
// 15 = 3 5

// The first three consecutive numbers to have three distinct prime factors are:
// 644 = 2² 7 23
// 645 = 3 5 43
// 646 = 2 17 19.

// Find the first four consecutive integers to have four distinct primes factors. What is the first of these numbers?
// 1001145 
// 134043
//return a std::vector with the primes factors of nbr (if nbr is a prime, the vector is empty)
void prime_factors(unsigned long nbr, const vector<unsigned long> &primes, std::vector<unsigned long> &facs) {
	unsigned long n = nbr/2;
	int f = 0;
	for (unsigned int i = 0; n >= primes[i]; ++i) 
		if (nbr % primes.at(i) == 0) 
			facs.push_back(primes[i]);
}

int main(int argc, char **argv){
	PrimeSeq ps;
	vector<unsigned long> primes;
	static const unsigned long MAX = 120000;
	primes.reserve(MAX);
	for (int i = 1; i <= MAX; ++i)
		primes.push_back(ps.next());

	std::vector<unsigned long> facs;
	prime_factors(134043, primes, facs);
	copy(facs.begin(), facs.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	prime_factors(134044, primes, facs);
	copy(facs.begin(), facs.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	prime_factors(134045, primes, facs);
	copy(facs.begin(), facs.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	prime_factors(134046, primes, facs);
	copy(facs.begin(), facs.end(), ostream_iterator<int>(cout, " ")); cout << endl;
	/*
	unsigned long i;
	for (i = MAX; ; ++i) {
		if (i % 1000 == 0)
			cout << "testing nbr: " << i << endl;
		facs.clear();
		prime_factors(i, primes, facs);
		if (facs.size() == 4) {
			prime_factors(i+1, primes, facs);
			if (facs.size() == 8) {
				prime_factors(i+2, primes, facs);
				if (facs.size() == 12) {
					prime_factors(i+3, primes, facs);
					if (facs.size() == 16) {
						cout << "break: " << i << endl;
						break;			//break the for loop
					}
				}
			}
		}

	}*/
} 	