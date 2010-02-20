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

// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

// returns true if s_nbr is a palindrome
bool is_pal(const string &nbr) {
	return equal(nbr.begin(), nbr.begin() + nbr.size()/2, nbr.rbegin());
}


int	main (int argc, char *const argv[]) {	
	int sum = 0;
	for (long i = 1; i < 1000000; ++i) {
		bitset<20> bs(i);
		string s = lexical_cast<string>( lexical_cast<ZZ>(bs.to_string()) );		// to get rid of leading zeroz, tunneling thrugh  a long
		if (is_pal(s) && is_pal(lexical_cast<string>(i)))
			sum += i;
	}
	cout << sum << endl;
}	