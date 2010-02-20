#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
// What is the largest prime factor of the number 317584931803?

using namespace std;
using namespace NTL;
//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

int main (int argc, char *const argv[]) {
//	unsigned long origin_nbr = 317584931803;
	ZZ origin_nbr = to_ZZ("317584931803");
	cout << origin_nbr << endl;
	PrimeSeq ps;

	ZZ current_val(origin_nbr);
	ZZ highest_factor = to_ZZ(0);
	for (int i = 1; i != 1000; ++i) {
		size_t current_prime = ps.next();
		while (current_val % current_prime == 0) {
			highest_factor = current_prime;
			current_val = current_val/current_prime;
		}
	}
	
	cout << "highest_factor: " << highest_factor << endl;

}
