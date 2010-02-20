#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>

//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest number that is evenly divisible by all of the numbers from 1 to 20

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm
 
/*
20			10 5 2 2 
19			
18			9 6 3 
17			17 
16			8 4 2
15			3 5
14			7 2
13			13
12			6 4 3 2
11
7 */

int main (int argc, char *const argv[]) {
	int n = 21;
	
	while (true) {
		if (n%20==0 && n%19==0 && n%18==0 && n%17==0 && n%16==0 && n%15==0 && n%14==0 && n%13==0 && n%12==0 && n%11==0 && n%7==0) {
			cout << "the number is: " << n << endl;
			break;
		}
		++n;
 	}
}
