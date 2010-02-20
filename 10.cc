#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

int main (int argc, char *const argv[]) {
	const int ONE_MILLION = 1000000;
	PrimeSeq ps;
	ZZ sum = to_ZZ("0");
	int current_prime = ps.next();
	do {
		sum += current_prime;
		current_prime = ps.next();
	} while (current_prime < ONE_MILLION);
 
	cout << sum << endl;
} 
