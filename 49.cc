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

void check_prime(int cand, int diff, const vector<int> &p) {
	if (binary_search(p.begin(), p.end(), cand) && binary_search(p.begin(), p.end(), cand+diff) && binary_search(p.begin(), p.end(), cand+2*diff)) {
		string cand1 = lexical_cast<string>(cand);
		string cand2 = lexical_cast<string>(cand + diff);
		string cand3 = lexical_cast<string>(cand+ 2*diff);
		sort(cand1.begin(), cand1.end());
		sort(cand2.begin(), cand2.end());
		sort(cand3.begin(), cand3.end());
		if (cand1 == cand2 && cand1 == cand3) 
			cout << cand << "" << cand+diff << "" << cand+2*diff << endl;
	}
}

int main(int argc, char **argv) {
	PrimeSeq ps;
	vector<int> primes;
	int prime = ps.next();
	while (prime < 10000) {
		primes.push_back(prime);
		prime = ps.next();
	}
	primes.erase(primes.begin(), lower_bound(primes.begin(), primes.end(), 1000));	//removes all 1,2,3-digit primes

	for (int i = 0; i < primes.size(); ++i) 
			check_prime(primes[i], 3330, primes);	
} 	