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

using namespace std;
using namespace NTL;
using namespace boost;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm
// What is the first term in the Fibonacci sequence to contain 1000 digits?

const ZZ& fibonaci(vector<ZZ> &fib, int n) {
	fib.push_back(fib[n-2] + fib[n-1]);
	return fib[n];
}

int	main (int argc, char *const argv[]) {	
	vector<ZZ> fib;
	fib.reserve(5000);				// a wild guess
		
	fib.push_back(to_ZZ(1));		//dummy so element at index i, is fibonaci nbr i.
	fib.push_back(to_ZZ(1));		// 1
	fib.push_back(to_ZZ(1));		// 2
	
	string nbr = lexical_cast<string>(fib[2]);
	int i = 2;
	do {
		++i;
		fibonaci(fib, i);
		nbr = lexical_cast<string>(fib[i]);
	} while ((nbr.size() < 1000));
	cout << i << endl;
} 
