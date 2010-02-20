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

//The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.
//Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

//HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
//pandigital nbr = 1234567890

std::set<int> prods;
long sum = 0;

inline void check_mult(int a, int b) {
	int prod = a*b;
	string pand_digit("123456789");
	string pand_cand = lexical_cast<string>(a) + lexical_cast<string>(b) + lexical_cast<string>(prod);
	string result;
	sort(pand_cand.begin(), pand_cand.end());
	set_intersection(pand_digit.begin(), pand_digit.end(), pand_cand.begin(), pand_cand.end(), back_inserter(result));		
	if (result.size() == 9 && pand_cand.size() == 9) //pand_cand is a pandigital 
		if (prods.count(prod) == 0) {
			prods.insert(prod);
			sum += prod;
		}
}

int	main (int argc, char *const argv[]) {	
	for (int a = 1; a <= 50; ++a) 
		for (int b = a; b <= 2000; ++b)
			check_mult(a,b);
	
	cout << sum << endl;
}	