#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>

// What is the 10001st prime number?

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

int main (int argc, char *const argv[]) {
	PrimeSeq ps;
	
	for (int i = 1; i <= 10001; ++i)
		cout << ps.next() << endl;

}
