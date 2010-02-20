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
// The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, 
// but it also has a rather interesting sub-string divisibility property.
// Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
// * d2d3d4=406 is divisible by 2
// * d3d4d5=063 is divisible by 3
// * d4d5d6=635 is divisible by 5
// * d5d6d7=357 is divisible by 7
// * d6d7d8=572 is divisible by 11
// * d7d8d9=728 is divisible by 13
// * d8d9d10=289 is divisible by 17
// Find the sum of all 0 to 9 pandigital numbers with this property.

bool sub_str_div_property(const string &pan) {
	static const int nbrs[] = {2, 3, 5, 7, 11, 13, 17};
	string::const_iterator it = ++pan.begin();	//an iterator to the 2nd element in pan
	for (int i = 0; i <= 6; ++i) {
		int nbr = lexical_cast<int>(string(it, it+3));
		if (nbr % nbrs[i] != 0)
			return false;
		++it;
	}
	return true;
}
int main(int argc, char **argv){
	string pan("0123456789");
	ZZ sum = to_ZZ(0);
	do {
			if (sub_str_div_property(pan))
				sum += lexical_cast<ZZ>(pan);
	} while (next_permutation(pan.begin(), pan.end()));
	cout << "sum is: " << sum  << endl;
} 	