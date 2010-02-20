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
// a^b for  (2 <= a <= 100) and (2 <= b <= 100)?

int	main (int argc, char *const argv[]) {	
	mpz_t base; 
	mpz_t ans;
	mpz_init(base);
	mpz_init(ans);
	std::set<mpz_class> nbrs;

	for (int a = 2; a <= 100; ++a) {
		mpz_set_ui(base, a);
		for (int b = 2; b <= 100; ++b) {
			mpz_pow_ui(ans, base, b);
			nbrs.insert(mpz_class(ans));
		}
	}	
	cout << nbrs.size() << endl;
}	