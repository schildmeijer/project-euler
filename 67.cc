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
	fstream infile("67.txt");
	if (!infile) {cerr << "error"; return 1;}
	
	vector<int> triangle;
	triangle.push_back(-1);		//dummy at index 0;
	string line;
	int nbr;
	while (getline(infile, line)) {
		stringstream ss;
		ss << line;
		while (ss >> nbr)
			triangle.push_back(nbr);
	}
	
	vector<int> index;
	index.reserve(101);
	index.push_back(0);
	for (int i = 1; i<=100; ++i) 
		index.push_back(index[i-1] + i);
	
	
	for (int row = 100; row >= 2; --row) {
		for (int i = 0; i < row-1; ++i) {
			triangle[ index[row-1]-i ] += max(triangle[ index[row]-i ], triangle[ index[row]-i-1 ]);
		}
	}
	cout << triangle[1] << endl;
	
}	