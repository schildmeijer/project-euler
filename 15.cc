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

int	main (int argc, char *const argv[]) {
	double a = 2;
	double b = 39;
	cout << pow(a, b) << endl;
	ZZ z = to_ZZ(pow(a, b));
	cout << z << endl;
	} 
