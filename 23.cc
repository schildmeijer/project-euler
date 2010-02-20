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

// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm
bool is_abundant(int nbr) {
	if (nbr == 1)		//a special case
		return false;
	
	int sq = sqrt(nbr);
	int sum = 1;
	for (int i = 2; i <= sq; ++i) {
		if (nbr%i == 0) {
			sum += i;
			if (i != nbr/i) 
				sum += nbr/i;
		}
	}
	return sum > nbr;
}

long func(int n) {
	if (n == 1)
		return 0;
	return n-1 + func(n-1); 
}

int	main (int argc, char *const argv[]) {
	vector<int> nbrs;
	for (int i = 1; i <= 28123; ++i)
		if (is_abundant(i))
			nbrs.push_back(i);
	
	vector<int> result(28123, 0);
	for (int i = 0; i < nbrs.size(); ++i) 
			for (int j = i; j < nbrs.size(); ++j)
				if (nbrs[i] + nbrs[j] < 28123)
					result[nbrs[i] + nbrs[j]] = 1;		// 1 means that there is a way to express i as the sum of two abundant numbers
	
	long sum = 0;
	for (int i = 0; i < result.size(); ++i)
		if (result[i] == 0) 
			sum += i;
	
	cout << sum << endl;
} 
