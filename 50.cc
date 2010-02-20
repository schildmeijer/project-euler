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

// The prime 41, can be written as the sum of six consecutive primes:
// 41 = 2 + 3 + 5 + 7 + 11 + 13
// This is the longest sum of consecutive primes that adds to a prime below one-hundred.
// The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
// Which prime, below one-million, can be written as the sum of the most consecutive primes?

bool is_sum_of_primes(const int prime, const vector<int> &primes, int &n) {
	for (int i = 0; i < primes.size() -1 && primes[i] < prime; ++i) {
		n = 0;
		int sum = 0;
		for (int j = i; j < primes.size() && primes[j] < prime; ++j) { //{0 1 2 3 4 5},  {1 2 3 4 5},  {2 3 4 5},  {3 4 5},  {4  5}, {5}
			sum += primes[j];
			++n;
			if (sum == prime) 
				return true;
			if (sum > prime) 
				break;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	PrimeSeq ps;
	vector<int> primes;
	primes.reserve(78498);		// 78498 primes that is < 1000 000
	int prime = 0;
	do {
		prime = ps.next();
		primes.push_back(prime);
	} while (prime < 1000000);
	
	int n = 0;
	int max_prime = 0;
	int max_n = 0;
	for (vector<int>::reverse_iterator it = primes.rbegin(); it != primes.rend(); ++it)
		if (is_sum_of_primes(*it, primes, n)) {
			if (n > max_n) {
				max_n = n;
				max_prime = *it;
				cout << "prime: "<< *it << "\t\tterms:  " << n << endl;
			}
		}
} 	