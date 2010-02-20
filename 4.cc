#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>

//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.
//Find the largest palindrome made from the product of two 3-digit numbers

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

inline string to_s(int n) {
	stringstream ss;
	ss << n;
	return ss.str();		//RVO
}
inline bool is_palindrome(const string & cand) {
	return(equal(cand.begin(), cand.begin()+cand.size()/2, cand.rbegin()));
}

int main (int argc, char *const argv[]) {
	int largest_pal = 0;
	for (int i = 100; i != 1000; ++i)
		for (int j = 100; j != 1000; ++j) {
			if (is_palindrome(to_s(i*j))) {
				largest_pal = i*j > largest_pal ? i*j : largest_pal; 
			}
		}
		cout << "largest palindrome of two three digits is: " << largest_pal;
}
