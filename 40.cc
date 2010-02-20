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
#include <boost/regex.hpp>	//for regex
#include <gmpxx.h>			//for c++


using namespace std;
using namespace NTL;
using namespace boost;

// An irrational decimal fraction is created by concatenating the positive integers:
// 0.123456789101112131415161718192021...
// It can be seen that the 12th digit of the fractional part is 1.

// If dn represents the nth digit of the fractional part, find the value of the following expression.
// d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000

int main(int argc, char **argv){
	string frac("0");
	for (int i = 1; i <= 1000000; ++i)
		frac.append(lexical_cast<string>(i));
	

	cout << lexical_cast<int>(frac[1])*lexical_cast<int>(frac[10])*lexical_cast<int>(frac[100])*lexical_cast<int>(frac[1000])*lexical_cast<int>(frac[10000])*lexical_cast<int>(frac[100000])*lexical_cast<int>(frac[1000000]) << endl;
} 	