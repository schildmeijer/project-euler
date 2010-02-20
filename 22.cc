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

// MARY","PATRICIA","LINDA"

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

int value(const string name) {
	int sum = 0;
	for (int i = 0; i < name.size(); ++i)
		sum += name[i] - 'A' + 1;
	
	return sum;
}

int	main (int argc, char *const argv[]) {
	ifstream infile("21.txt");
	if (!infile) {
		cerr << "error" << endl;
		return 1;
	}
	
	vector<string> names;
	names.reserve(5000);
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
	
	sort(names.begin(), names.end());
	
	long sum = 0;
	for (int i = 0; i < names.size(); ++i) {
		sum += (i+1) * value(names[i]);
		cout << "sum: " << sum << endl;
	}
} 
