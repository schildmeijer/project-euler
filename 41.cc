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

// We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. 
// For example, 2143 is a 4-digit pandigital and is also prime.

// What is the largest n-digit pandigital prime that exists?
bool is_n_pan(string cand) {
	if (cand.size() > 9) {
		int nbr = 10;
		do {
			if (contains(cand, lexical_cast<string>(nbr)))
				erase_first(cand, lexical_cast<string>(nbr++));
			else {
				cout << "couldn't find: " << nbr << endl; 
				return false;
			}
			
		} while (cand.size() > 9);
		string pan("123456789");
		sort(cand.begin(), cand.end());
		
		return (cand.size() == 9 && equal(cand.begin(), cand.end(), pan.begin()));
	}
	int size = cand.size();
	string pan;
	for (int i = 1; i <= size; ++i) {
		pan += lexical_cast<string>(i);
	}
	sort(cand.begin(), cand.end());
	return equal(cand.begin(), cand.end(), pan.begin());
}
int main(int argc, char **argv){
	PrimeSeq ps;
	while (true) {
		ZZ cand = to_ZZ(ps.next());
		if (is_n_pan(lexical_cast<string>(cand)))
			cout << "FOUND NEW CAND: " << cand << endl;
	}
} 	