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


int main(int argc, char **argv){
	vector<int> perp(1000,0);

	int hypo = 0;
	double hypo_d = 0;
		for (int cat1 = 1; cat1 <= 900; ++cat1)
			for (int cat2 = cat1; cat2 < 1000; ++cat2) {
				hypo = sqrt(cat1*cat1 + cat2* cat2);
				hypo_d = sqrt(cat1*cat1 + cat2* cat2);
				if (hypo_d - hypo == 0 && cat1 + cat2 + hypo < 1000) 
					++perp[cat1 + cat2 + hypo];
			}
				for (int i = 0; i <= 999; ++i)
				cout << i << "\t" << perp[i] << endl;
} 	