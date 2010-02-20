#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iterator>
#include <map>
#include <utility>	//for std::make_pair

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

//	Which starting number, under one million, produces the longest chain?

ZZ h(ZZ nbr, int &iter) {
	++iter;
	if (nbr%4 != 1)
		return nbr;
	return h((nbr-1)/4, iter);
}

ZZ g(ZZ nbr, int &iter){
	++iter;
	if (nbr%2 == 1)
		return nbr;
	return g(nbr/2, iter);
}
int collatz(ZZ nbr) {
	cout << "[collatz]starting nbr: " << nbr << endl;
	int iterations = 0;
	//ZZ starting_nbr = nbr;	//for cache
	//static map<int, int> cache;
	
	while (nbr != 1) {
	//	map<int, int>::iterator it = cache.find(nbr);
	//	if (it != cache.end()) {		//a cache hit, use it!
	//		iterations += it->second;
	//		break;
	//	}
		//nbr = nbr%2 == 0 ? nbr/2 : 3*nbr + 1;		//old fomula
		
		if (nbr%4 == 0) {
			nbr = g(nbr, iterations);
		}
		if (nbr%4 == 1) {
			nbr = 3*h(nbr, iterations)+1;
		}
		if (nbr%4 == 2) {
			nbr = nbr/2;
			++iterations;
		}
		if (nbr%4 == 3) {
			nbr = (3*nbr+1)/2;
			++iterations;
		}
	
		//++iterations;		//for old formula
	}
	//cache.insert(make_pair(starting_nbr, iterations));
	return iterations;
}

int main (int argc, char *const argv[]) {
	int current_max = 0;
	int start_nbr = 0;
	for (int i = 1; i <= 1000000 ; ++i) {	
		int cand = collatz(to_ZZ(i));
		if (cand > current_max) {
			current_max = cand;
			start_nbr = i;
		}
	}
	
	cout << "starting number: "<< start_nbr << endl; 
} 
