#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iterator>
#include <map>
#include <utility>	//for std::make_pair
//#include <boost/lambda/lambda.hpp>
#include <numeric>

using namespace std;
using namespace NTL;
//using namespace boost::lambda;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

// If the numbers 1 to 5 are written out in words: one, two, three, four, five; there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)
// contains 20 letters.

int chars(int nbr) {
	if (nbr == 0)									return 0;	// 1 --> 19
	if (nbr == 1)  {cout << "one" << endl;			return 3; }
	if (nbr == 2)  {cout << "two" << endl;			return 3; }
	if (nbr == 3)  {cout << "three" << endl;		return 5; }
	if (nbr == 4)  {cout << "four" << endl;			return 4; }
	if (nbr == 5)  {cout << "five" << endl;			return 4; }
	if (nbr == 6)  {cout << "six" << endl;			return 3; }
	if (nbr == 7)  {cout << "seven" << endl;		return 5; }
	if (nbr == 8)  {cout << "eight" << endl;		return 5; }
	if (nbr == 9)  {cout << "nine" << endl;			return 4; }
	if (nbr == 10) {cout << "ten" << endl;			return 3; }	
	if (nbr == 11) {cout << "eleven" << endl;		return 6; }
	if (nbr == 12) {cout << "twelve" << endl;		return 6; }
	if (nbr == 13) {cout << "thirteen" << endl;		return 8; }
	if (nbr == 14) {cout << "fourteen" << endl;		return 8; }
	if (nbr == 15) {cout << "fifteen" << endl;	    return 7; }
	if (nbr == 16) {cout << "sixteen" << endl;		return 7; }
	if (nbr == 17) {cout << "seventeen" << endl;	return 9; }
	if (nbr == 18) {cout << "eighteen" << endl;		return 8; }
	if (nbr == 19) {cout << "nineteen" << endl;		return 8; }
	
	if (nbr >= 20 && nbr <=99) {								// 20 --> 99
		if (nbr >= 20 && nbr < 30)  {cout << "twenty-";			return 6+chars(nbr%10); }
		if (nbr >= 30 && nbr < 40)  {cout << "thirty-";			return 6+chars(nbr%10); }
		if (nbr >= 40 && nbr < 50)  {cout << "forty-";			return 5+chars(nbr%10); }
		if (nbr >= 50 && nbr < 60)  {cout << "fifty-";			return 5+chars(nbr%10); }
		if (nbr >= 60 && nbr < 70)  {cout << "sixty-";			return 5+chars(nbr%10); }
		if (nbr >= 70 && nbr < 80)  {cout << "seventy-";		return 7+chars(nbr%10); }
		if (nbr >= 80 && nbr < 90)  {cout << "eighty-";			return 6+chars(nbr%10); }
		if (nbr >= 90 && nbr < 100) {cout << "ninety-";			return 6+chars(nbr%10); }
	}
	
	if (nbr >= 100 && nbr <= 999) {								// 100-->999
		if (nbr == 100) {cout << "one hundred" << endl;				return 10;}
		if (nbr == 200) {cout << "two hundred" << endl;				return 10;}
		if (nbr == 300) {cout << "three hundred" << endl;			return 12;}
		if (nbr == 400) {cout << "four hundred" << endl;			return 11;}
		if (nbr == 500) {cout << "five hundred" << endl;			return 11;}
		if (nbr == 600) {cout << "six hundred" << endl;				return 10;}
		if (nbr == 700) {cout << "seven hundred" << endl;			return 12;}
		if (nbr == 800) {cout << "eight hundred" << endl;			return 12;}
		if (nbr == 900) {cout << "nine hundred" << endl;			return 11;}
		
		if (nbr >= 100 && nbr < 200) {cout << "one hundred and" << endl;				return 13+chars(nbr%100);}
		if (nbr >= 200 && nbr < 300) {cout << "two hundred and" << endl;				return 13+chars(nbr%100);}
		if (nbr >= 300 && nbr < 400) {cout << "three hundred and" << endl;				return 15+chars(nbr%100);}
		if (nbr >= 400 && nbr < 500) {cout << "four hundred and" << endl;				return 14+chars(nbr%100);}
		if (nbr >= 500 && nbr < 600) {cout << "five hundred and" << endl;				return 14+chars(nbr%100);}
		if (nbr >= 600 && nbr < 700) {cout << "six hundred and" << endl;				return 13+chars(nbr%100);}
		if (nbr >= 700 && nbr < 800) {cout << "seven hundred and" << endl;				return 15+chars(nbr%100);}
		if (nbr >= 800 && nbr < 900) {cout << "eight hundred and" << endl;				return 15+chars(nbr%100);}
		if (nbr >= 900 && nbr < 1000){cout << "nine hundred and" << endl;				return 14+chars(nbr%100);}
	}
	if (nbr == 1000) {cout << "one thousand" << endl;				return 11;}
}

int	main (int argc, char *const argv[]) {
	int sum = 0;
	for (int i = 1; i<= 1000; ++i)
		sum += chars(i);
	cout << sum << endl;
} 
