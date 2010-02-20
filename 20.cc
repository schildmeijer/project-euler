#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iterator>
#include <map>
#include <utility>	//for std::make_pair
#include <ctime>   /* for C routines time and localtime */
#include <boost/lambda/lambda.hpp>
#include <numeric>

using namespace std;
using namespace NTL;
using namespace boost::lambda;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm


ZZ fac(int n) {
	if (n == 0)
		return to_ZZ(1);
	
	return n * fac(n-1);
}

int to_i(char ch) {
	stringstream ss;
	ss << ch;
	int nbr;
	ss >> nbr;
	return nbr;
}


int	main (int argc, char *const argv[]) {
	ZZ nbr = fac(100);
	stringstream ss;
	ss << nbr;
	string str_nbr;
	ss >> str_nbr;
	vector<int> vec_nbr;
	vec_nbr.reserve(str_nbr.size());
	transform(str_nbr.begin(), str_nbr.end(), back_inserter(vec_nbr), to_i);
	int sum = 0;
	for_each(vec_nbr.begin(), vec_nbr.end(), sum += _1);
	cout << sum << endl;
} 
