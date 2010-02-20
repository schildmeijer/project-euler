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

//Which is the first triangle number to have over five-hundred divisors?
int divisors_trial(long val) {
	int nbr = 0;
	for (long i = 1; i <= val; ++i) 
		if (val%i == 0) {
			//cout << i << endl;
			++nbr;
		}
	return nbr;
}

int divisors_sq(long val) {
	long sq = sqrt(val);
	int nbr = 0;
	for (long i = 1; i <= sq; ++i)
		if (val%i == 0) {
			//cout << i << endl;
			//cout << val/i << endl;
			nbr += 2;
		}
	return nbr;
}

int main (int argc, char *const argv[]) {
	static const int NBRS = 1000000;
	vector<long> naturals(NBRS);
	naturals[0] = 0;
	naturals[1] = 1;
	
	for (int i = 2; i < NBRS; ++i) 
		naturals[i] = i + naturals[i-1];
	
	
	for (int i = 0; i < NBRS; ++i) {
		cout << i << " "<< endl;
 		if (divisors_trial(naturals[i]) > 500) {
			cout << "number: " << naturals[i] << endl;
			break;
		}
	}
} 
