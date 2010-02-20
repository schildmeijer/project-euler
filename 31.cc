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
#include <gmpxx.h>		//for c++

using namespace std;
using namespace NTL;
using namespace boost;

// g++ -I/usr/local/include -I/usr/local/include/boost-1_33_1 -I/usr/local/include/gmp-4.2.1 -L/usr/local/lib 27.cc -o main -lntl -lm -lgmpxx -lgmp

int	main (int argc, char *const argv[]) {	
	
	int p = 1;		// using only one £2
	
	for (int hundreds = 0; hundreds <= 2; ++hundreds)
		for (int fiftys = 0; fiftys <= 4; ++fiftys)
			for (int twenty = 0; twenty <= 10; ++twenty)
				for (int tens = 0; tens <= 20; ++tens)
					for (int fives = 0; fives <= 40; ++fives)
						for (int twos = 0; twos <= 100; ++twos)
							for (int ones = 0; ones <= 200; ++ones)
								if (hundreds*100 + fiftys*50 + twenty*20 + tens*10 + fives*5 + twos*2 + ones*1 == 200)
									++p;
	cout << p << endl;
}	