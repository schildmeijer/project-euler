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

//How many circular primes are there below one million?

//circular rotate a given number, nbr. eg. 123 -> 312
void rotate_nbr(string &s_nbr) {
	string nbr_rot(lexical_cast<string>(*--s_nbr.end()));
	copy(s_nbr.begin(), --s_nbr.end(), back_inserter(nbr_rot));
	s_nbr.swap(nbr_rot);
}

int	main (int argc, char *const argv[]) {	
	PrimeSeq ps1, ps2;
	vector<string> primes;
	
	int curr_prime = 0;
	do {
		curr_prime = ps1.next();
		primes.push_back(lexical_cast<string>(curr_prime));
	} while (curr_prime < 1000000);		
	sort(primes.begin(), primes.end());
	curr_prime = 0;
	int circular_primes = 0;	
	do {
		curr_prime = ps2.next();
		string s_prime = lexical_cast<string>(curr_prime);
		int n = 0;
		for (int i = 1; i <= s_prime.size(); ++i) {
			if (binary_search(primes.begin(), primes.end(), s_prime))
				++n;
			rotate_nbr(s_prime);
		}
		if (n == s_prime.size()) {
			++circular_primes;
			cout << "the prime is: " << s_prime << endl;
		}
	} while (curr_prime < 1000000);

	cout << circular_primes << endl;
}	