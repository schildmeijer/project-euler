#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iterator>

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm
//Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

int main (int argc, char *const argv[]) {
	ifstream infile("13.txt");
	if (!infile){
		cerr << "could not open the file" << endl;
		return 1;
	}
	
	string large_nbr;
	vector<ZZ> nbrs;
	while (getline(infile, large_nbr)) 
		nbrs.push_back(to_ZZ(large_nbr.c_str()));
	
	ZZ sum = to_ZZ("0");
	for (vector<ZZ>::iterator it = nbrs.begin(); it != nbrs.end(); ++it)  {
	//	cout << "sum is current: " << sum << endl;
		sum += *it;
	}
	
	//cout << sum << endl;
	stringstream ss;
	ss << sum;
	string str_sum;
	ss >> str_sum;
	copy(str_sum.begin(), str_sum.begin()+10, ostream_iterator<char>(cout,""));
	
} 
