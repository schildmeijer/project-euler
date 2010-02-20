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

using namespace std;
using namespace NTL;
//using namespace boost::lambda;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
// 012   021   102   120   201   210


int	main (int argc, char *const argv[]) {	
	string nbr("0123456789");
	for (int i = 1; i < 1000000; ++i)
		next_permutation(nbr.begin(), nbr.end());
	cout << nbr << endl;
} 
