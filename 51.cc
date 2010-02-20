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
#include <numeric>	//for adjacent_difference
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

// By replacing the 1st digit of *57, it turns out that six of the possible values: 157, 257, 457, 557, 757, and 857, are all prime.

// By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes, 
// yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, 
// is the smallest prime with this property.

// Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
int check_prime(int p, const vector<int> &primes) {		// 12345,	1,2,3,4,5
								//			12, 13, 14, 15, 23, 24, 25, 34, 35, 45
								//			123, 124, 125, 134, 135, 145, 234, 235,245, 345
								//			1234, 1235, 1245, 1345, 2345
								//			12345
	vector<int> index;
	index.push_back(1); index.push_back(2); index.push_back(3);	index.push_back(4);	index.push_back(5);
	index.push_back(12); index.push_back(13); index.push_back(14); index.push_back(15);index.push_back(23); index.push_back(24); index.push_back(25); index.push_back(34);	index.push_back(35); index.push_back(45);
	index.push_back(123); index.push_back(124); index.push_back(125); index.push_back(134);	index.push_back(135);index.push_back(145); index.push_back(234); index.push_back(235); index.push_back(245); index.push_back(345);
	index.push_back(1234); index.push_back(1235); index.push_back(1245);	index.push_back(1345);	index.push_back(2345);
	index.push_back(12345);
	
	for (int i = 0; i < index.size(); ++i) {
		string sprime = lexical_cast<string>(p);
		int n = 0;
		for (int j = 0; j <= 9; ++j) {
			string ii = lexical_cast<string>(index[i]);		// ii is i.e 1234
			for (int k = 0; k < ii.size(); ++k) 
				sprime[ lexical_cast<int>(ii[k])-1 ] = lexical_cast<char>(j);
			if (binary_search(primes.begin(), primes.end(), lexical_cast<int>(sprime))) 
				++n;
			if (n == 8) {
				cout << "n is: " << n << endl;
				cout << "FOUND: " << sprime << endl;
				cout << "changed index " << ii << endl;
				int val;
				cin >> val;
			}
		}
	}
}
int main(int argc, char **argv) {
	PrimeSeq ps;
	vector<int> primes;
	primes.reserve(72815);			// 72815 primes [56000, 1000.000]
	while (ps.next() < 55000)
		; // ignore all primes E[2, 56000]
	
	int prime = ps.next();
	while (prime < 1000000) {
		primes.push_back(prime);
		prime = ps.next();	
	} 
	for (int i = 0; i < primes.size(); ++i) {
		cout << "about to test; " << primes[i] << endl;		// 120383 --> 121313
		check_prime(primes[i], primes);
	}
} 	