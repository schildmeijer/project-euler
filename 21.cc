#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iterator>
#include <map>
#include <utility>	//for std::make_pair
#include <boost/lambda/lambda.hpp>
#include <boost/foreach.hpp>

using namespace std;
using namespace NTL;
using namespace boost::lambda;

// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
// The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
// Evaluate the sum of all the amicable numbers under 10000. 
//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

int d(int n) {
	int sum_of_divisors = 0;
	
	for (int i = n-1; i>=1; --i) {
		if (n%i == 0)
			sum_of_divisors += i;
	}
	return sum_of_divisors;
}

int	main (int argc, char *const argv[]) {
	map<int, int> amicable_pairs;
	
	for (int i = 1; i < 10000; ++i) 
		amicable_pairs.insert(map<int, int>::value_type(i, d(i)));
	
	int sum = 0;
	for (map<int, int>::iterator it = amicable_pairs.begin(); it != amicable_pairs.end(); ) {
		if (amicable_pairs.find(it->second)->second == it->first && it->first != it->second) {
			sum += it->first + it->second;
			map<int, int>::iterator tmp_it(it); 
			++it;
			amicable_pairs.erase(tmp_it->first); 
		}
		else
			++it;
	}
	cout << sum << endl;
} 
