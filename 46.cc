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

// It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
// 9 = 7 + 2*1²		2 * 1
// 15 = 7 + 2*2²	2 * 4
// 21 = 3 + 2*3²	2 * 9
// 25 = 7 + 2*3²	2 * 16
// 27 = 19 + 2*2²	2 * 25
// 33 = 31 + 2*1²	2 * 36
//					2 * 49
//					2 * 64
// It turns out that the conjecture was false.
// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

struct remove_primes_and_odd : public unary_function<unsigned long, bool> {
	remove_primes_and_odd(const vector<unsigned long> &p) : primes(p) {}
	bool operator()(unsigned long cand) {
		return binary_search(primes.begin(), primes.end(), cand) || cand % 2 == 0;
	}
private:
	const vector<unsigned long> &primes;
};

//returns true if we cant write nbr as the sum of a prime and twice a square
bool check(unsigned long nbr, const vector<unsigned long> &p) {
	long rest;
	int n = 0;
	do {
		++n;
		rest = nbr - 2*n*n; 
	} while (!binary_search(p.begin(), p.end(), rest) && rest > 0);
	return rest > 0;
}

int main(int argc, char **argv){
	vector<unsigned long> primes;
	PrimeSeq ps;
	const static unsigned int MAX = 6000;
	primes.reserve(MAX);
	for (int i = 0; i < MAX; ++i)
		primes.push_back(ps.next());
	
	vector<unsigned long> odd_comps;
	odd_comps.reserve(MAX);						//instead of MAX, should use *--primes.end()
	for (unsigned long i = 4; i <= MAX; ++i)	//instead of MAX, should use *--primes.end(), NB. the sentinel, i,  could overflow
		odd_comps.push_back(i);
	
	odd_comps.erase(remove_if(odd_comps.begin(), odd_comps.end(), remove_primes_and_odd(primes)), odd_comps.end());	
	
	BOOST_FOREACH(unsigned long cand, odd_comps) {
		if (!check(cand, primes)) {
			cout << "FOUND " << cand << endl;
			break;
		}
	}		
} 	