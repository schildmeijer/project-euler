#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <NTL/quad_float.h>
#include <NTL/xdouble.h>
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
#include <gmp.h>		//for c
#include <gmpxx.h>		//for c++

using namespace std;
using namespace NTL;
using namespace boost;

// g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm
// Find the value of d  1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

// 877

string to_s(const mpf_class &fp) {
	stringstream ss;
	ss.precision(cout.precision());
	ss << fp;
	return ss.str();
}

bool check_cycle(const vector<char> &cycle, const string &d) {
	int j = 0;
	for (int i = 2; i < d.size()-10; ++i) {		//NB -3
		if (cycle[j++] != d[i])
			return false;
		if (j >= cycle.size())
			j = 0;
	}
	return true;	
}

//returns the length of the reccuring cycle in d
int recurring_cycle(const string &d) {
	vector<char> cycle;
	cycle.push_back(d[2]);
	for (int i = 3; i < d.size(); ++i) {
		if (d[i] != cycle[0]) 
			cycle.push_back(d[i]);

		else {	
			//the cycle might be in the vector
			//check if the rest of d is just a cycle multiple of cycle
			//otherwise continue fill vector with digits
			if (check_cycle(cycle, d)) 
				return cycle.size();
			cycle.push_back(d[i]);
		}
	}
	return -1;	
}
//0.00740740740740	3
int	main (int argc, char *const argv[]) {	
	const int MAX = 4000;
	cout.precision(MAX);
	
    const mpf_class num(1, 15000);	   // 15000 bits precision (at least)
	
	double denom = 135;
	mpf_class den(denom, 15000);
	//mpf_class res(num/den); 
//	string test = to_s(res);
//	string test("0.007407407407407407"); 
//	string test("0.00740740740740");
//	reverse(test.begin(), test.end());
//	cout << "number of digits in the recurring cycle in: " << test << " is " << recurring_cycle(test) << endl; 
	
	int max_rec_cycle = 0;
	int value = 0;
	for (int i = 1; i < 1000; ++i) {
		cout << "investigating: " << i << endl;
		double denom = i;
		mpf_class den(denom, 15000);
		mpf_class res(num/den);   
		string d = to_s(res);
		if (d.size() < MAX)		// if true; then 1/d has a finite decimal development (eg. 1/2, 1/4, 1/8 etc.) will not have longest reccuring cycle
			continue;
		
		//find how long the recurring cycle is!
		reverse(d.begin(), d.end());
		int cand = recurring_cycle(d);
		if (cand > max_rec_cycle) {
			max_rec_cycle = cand;
			value = i;
		}
	} 
	cout << value << endl; 
} 