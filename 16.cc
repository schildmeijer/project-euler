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
#include <numeric>

using namespace std;
using namespace NTL;
using namespace boost::lambda;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm
// what is the sum of the digits in 2^1000;

struct to_i : public unary_function<string, int> {
	int operator()(char ch) {
		stringstream ss;
		ss << ch;
		int val;
		ss >> val;
		return val;
	}
};

int	main (int argc, char *const argv[]) {
	ZZ nbr = to_ZZ(1);
	for (int i = 1; i <=1000; ++i)
		nbr *= 2; 
	
	stringstream ss;
	ss << nbr;
	string str_nbr = ss.str();
	vector<int> vec_nbr;
	transform(str_nbr.begin(), str_nbr.end(), back_inserter(vec_nbr), to_i());
	
	int sum = 0;
	//cout << accumulate(vec_nbr.begin(), vec_nbr.end(), sum) << endl;
	for_each(vec_nbr.begin(), vec_nbr.end(), sum += _1);
	cout << sum << endl;
} 
