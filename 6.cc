#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>

//The sum of the squares of the first ten natural numbers is,
//1² + 2² + ... + 10² = 385

//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)² = 55² = 3025

//Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 385 = 2640.

//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

int main (int argc, char *const argv[]) {
	long sum_of_sq = 0;
	for (int i = 1; i <= 100; ++i)
		sum_of_sq += i*i;
	
	long sq_of_sum = 0;
	for (int i = 1; i <= 100; ++i)
		sq_of_sum += i;
	
	sq_of_sum = sq_of_sum*sq_of_sum;
	
	cout << "the difference is: " << sq_of_sum - sum_of_sq << endl;
}
