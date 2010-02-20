#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iterator>
#include <map>
#include <utility>	//for std::make_pair
#include <ctime>   /* for C routines time and localtime */
//#include <boost/lambda/lambda.hpp>
#include <numeric>

using namespace std;
using namespace NTL;
//using namespace boost::lambda;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

class Date {
public:
    Date() {
		year = 1900;
		month = 1; 
		day = 1;
		week_day = 1;	// 1 == monday, ..., 7 == sunday
	}
	
	void print () { cout << year << "\t" << month << "\t" << day << "\t" << week_day << endl; }
	
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const{ return day; }
    int getWeekday() const{ return week_day; }
	
    void next() {
		//check for leap!
		if (day == 28 && month == 2 && year % 400 == 0) {
			cout << "400 leap++" << endl;
			day++;
			week_day++;
			if (week_day > 7)
				week_day = 1;
			return;
		}
		else if (day == 28 && month == 2 && year % 4 == 0 && year % 100 != 0) {
			cout << "4 leap++" << endl;
			day++;
			week_day++;
			if (week_day > 7)
				week_day = 1;
			return;
		}
		
		day++;
		week_day++;
		if (week_day > 7)
			week_day = 1;
		
		if (day > daysPerMonth[month-1]) {
			day = 1;
			month++;
		}
		
		if (month > 12) {
			month = 1;
			year++;
		}
	}
private:
	int year;                    // the year (four digits)
    int month;                   // the month (1-12)
    int day;                     // the day (1-..)
	int week_day;
    static int daysPerMonth[12]; // number of days in each month
};

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int	main (int argc, char *const argv[]) {
	Date d;
	for (int i = 1; i <= 366; ++i) {
		d.print();
		d.next();
	}		// date is 1901 jan 1st, tuesday
	
	int n= 0;	//number of sundays at the first of the month
	while (d.getYear() != 2000 || d.getMonth() != 12 || d.getDay() != 31) {
		if (d.getDay() == 1 && d.getWeekday() == 7)
			++n;
		d.print();
		d.next();
	}
	cout << n << endl;
} 
