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
#include <bitset>
#include <utility>	//for std::make_pair
#include <boost/lambda/lambda.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/algorithm/string.hpp>
#include <gmpxx.h>			//for c++


using namespace std;
using namespace NTL;
using namespace boost;
// The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:
// 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

// By converting each letter in a word to a number according to its alphabetical position 
// and adding these values, we can form a number for any given word. For example, SKY, becomes, 19 + 11 + 25 = 55 = t_{10}.

int value_of(const string& word) {
	int sum = 0;
	for (string::const_iterator it = word.begin(); it != word.end(); ++it) 
		sum += *it - 'A' + 1;		// all words in 42.txt is upper case 
	return sum;
}
int main(int argc, char **argv){
	ifstream infile("42.txt");
	if (!infile) {
		cerr << "error" << endl;
		return 1;
	}
	
	vector<string> names;
	names.reserve(2000);
	string line;
	getline(infile, line);
	int low_bound = 0;
	int high_bound = 0;
	while (line.find("\"", high_bound) != string::npos) {
		low_bound = line.find("\"", low_bound) + 1;
		high_bound = line.find("\"", low_bound+1);
		names.push_back(line.substr(low_bound, (high_bound-low_bound)));
		low_bound = high_bound+1;
		high_bound += 3;
	}
	vector<int> tri_nbr;
	tri_nbr.reserve(200);
	for (int i = 1; i <= 200; ++i)
		tri_nbr.push_back(i*(i+1)/2);
	
	int n = 0;
	for (vector<string>::iterator it = names.begin(); it != names.end(); ++it)
		if (binary_search(tri_nbr.begin(), tri_nbr.end(), value_of(*it)))
			++n;
	
	cout << n << endl;	
} 	