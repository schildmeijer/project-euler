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

// If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

// {20,48,52}, {24,45,51}, {30,40,50}

// For which value of p < 1000, is the number of solutions maximised?

inline bool perpendicular(int cat1, int cat2, int hypo) { 
	return sqrt(cat1*cat1 + cat2*cat2) == hypo;
}

int main(int argc, char **argv){
	int sol = 0;
	int max_sol = 0;
	int max_p = 0;
	for (int p = 999; p > 20; --p) {
		cout << "p: " << p << endl;
		for (int cat1 = 1; cat1 <= 400; ++cat1) 
			for (int cat2 = 1; cat2 <= 400; ++cat2) {
				int hypo = p - cat1 - cat2;
				if (perpendicular(cat1, cat2, hypo))
					++sol;
			}
				if (sol > max_sol) {
					max_sol = sol;
					max_p = p;
				}
		sol = 0;
	}
	cout << max_p << endl;
} 	