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
#include <utility>	//for std::make_pair
#include <boost/lambda/lambda.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>
//#include <gmp.h>		//for c
#include <gmpxx.h>		//for c++

using namespace std;
using namespace NTL;
using namespace boost;

// g++ -I/usr/local/include -I/usr/local/include/boost-1_33_1 -I/usr/local/include/gmp-4.2.1 -L/usr/local/lib 27.cc -o main -lntl -lm -lgmpxx -lgmp

int	main (int argc, char *const argv[]) {	
	int value = 1;
	int diag_sum = 1;
	for (int i = 0; i < 500; ++i) {
		value = value + i*8+2;
		for (int j = 0; j < 4; ++j) 
			diag_sum += value+(2*j)*(i+1);
	}
	cout << diag_sum << endl;
}	