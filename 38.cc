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

// Take the number 192 and multiply it by each of 1, 2, and 3:
// 192 * 1 = 192
// 192 * 2 = 384
// 192 * 3 = 576
// By concatenating each product we get the 1 to 9 pandigital, 192384576.

// The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645.

// Excluding the trivial example, 987654321, what is the largest 1 to 9 pandigital number that can be formed this way?

//returns true if cand is a pandigital number
bool is_pan(string cand) {
	static const string pan("123456789");
	sort(cand.begin(), cand.end());
	return equal(pan.begin(), pan.end(), cand.begin());
}

// returns true if nbr can be multiplied, and concatenated to a pandigital nbr
bool calc(int nbr) {
	string conc(lexical_cast<string>(nbr));
	
	int n = 2;	
	while (conc.size() <= 9) {
		if (conc.size() == 9 && is_pan(conc)) {
			cout << "found: " << conc << endl;
			return true;
		}
		int prod = nbr * n++;
		conc += lexical_cast<string>(prod);
	}
}

int main(int argc, char **argv){
	for (int i = 1; i < 10000; ++i)
		(calc(i));
} 	