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

std::vector<int> triangle;				//global variable, so i dont need to pass it as a parameter

int sum(int index, int row) {
	if (index+row >= triangle.size())	// this node does not have any siblings
		return triangle[index];
	
	return triangle[index] + max(sum(index+row, row+1), sum(index+(row+1), row+1));	//node has two siblings
}

int	main (int argc, char *const argv[]) {
	int nodes = 0;
	const int rows = 15;					//the number of rows in triangle
	for (int i = 1; i <= rows; ++i)			//determines the number of nodes
			nodes += i; 
	triangle.reserve(nodes);
	
	triangle.push_back(-1);	// dummy at [0]
	
	ifstream infile("18.txt");
	if (!infile) { cerr << "error" << endl; return 1; }
	
	string line;
	int nbr;
	while (getline(infile, line)) {
		stringstream ss;
		ss << line;
		while (ss >> nbr)
			triangle.push_back(nbr);
	}
		
	
	cout << "sum is: " << sum(1,1) << endl;	//first node, first row
} 
