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

// The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, 
// and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
// Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
//
// NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

bool remove_from_left(long nbr, const vector<long> &primes) {
	string s_nbr = lexical_cast<string>(nbr);
	int length = s_nbr.size();
	for (int i = 0; i < length; ++i) {
		if ( !binary_search(primes.begin(), primes.end(), nbr))
			return false;
		string s(++s_nbr.begin(), s_nbr.end());
		if (!s.empty())
			nbr = lexical_cast<long>(s);
		s_nbr = s;
	}
	return true;
}

inline bool remove_from_right(long nbr, const vector<long> &primes) {
	do {
		if ( !binary_search(primes.begin(), primes.end(), nbr))
			return false;
		nbr /= 10; 
	
	} while (nbr != 0);
	return true;
}

int	main (int argc, char *const argv[]) {	
	PrimeSeq ps;
	int found = 0;					//nbr of searched primes found
	unsigned long sum = 0;
	vector<long> primes;
	for (int i = 1; i <= 4; ++i)	// primes 2,3, 5 and 7.
		primes.push_back(ps.next());
	while (found != 11)		{		//there only exists 11 sucha primes
		long cand = ps.next();
		primes.push_back(cand);
		if (remove_from_left(cand, primes) && remove_from_right(cand, primes)) {
			sum += cand;
			++found;
		}
	}
	cout << sum << endl;
}	