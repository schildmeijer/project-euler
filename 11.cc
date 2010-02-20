#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <sstream>
#include <math.h>
#include <fstream>
#include <iterator>

using namespace std;
using namespace NTL;

//g++ -I/usr/local/include -L/usr/local/lib main.cpp -o main -lntl -lm

long check_diag(const vector<int> & matrix) {
	long max_prod = 0;
	
	for (int i = 0; i <= 336; ++i) {
		long cand = matrix[i] * matrix[i+21] * matrix[i+42] * matrix[i+63];
		max_prod = cand > max_prod ? cand : max_prod;
		if ( (i-16)%20 == 0 )	// right edge
			i += 3;
	}
	return max_prod;
}

void do_weird_operation(vector<int> &matrix) {
	vector<int> new_matrix;
	new_matrix.reserve(20*20);
	for (int i = 0; i < 20; ++i) 
		copy(matrix.rend()-(20+i*20), matrix.rend()-i*20, back_inserter(new_matrix));	
	
	// copy elements from new_matrix to matrix
	matrix.clear();
	copy(new_matrix.begin(), new_matrix.end(), back_inserter(matrix));
}

long check_rows(const vector<int> &matrix) {
	long max_prod = 0;
	for (int i = 0; i <= 396; ++i ) {
		long cand = matrix[i] * matrix[i+1] * matrix[i+2] * matrix[i+3];
		max_prod = cand > max_prod ? cand : max_prod;
		if ( (i-16)%20 == 0 ) 	// right edge NB. should it be 20, not 19?
			i += 3;
	}
	return max_prod;
}

long check_columns(const vector<int> &matrix) {
	vector<int> new_matrix;
	new_matrix.reserve(20*20);
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
			new_matrix.push_back(matrix[i+j*20]);		//transpose
	
	return check_rows(new_matrix);
}

int main (int argc, char *const argv[]) {
	ifstream infile("matrix.txt");
	if (!infile) {
		cerr << "could not open data-file";
		return 1;
	}	
	vector<int> matrix;
	matrix.reserve(20*20);
	copy(istream_iterator<int>(infile), istream_iterator<int>(), back_inserter(matrix));
	
	long max_prod = check_diag(matrix);				//check diag, (left to right)
	
	long max_prod_cand = check_rows(matrix);		//check rows
	max_prod = max_prod_cand > max_prod ? max_prod_cand : max_prod;
	
	max_prod_cand = check_columns(matrix);			//check columns
	max_prod = max_prod_cand > max_prod ? max_prod_cand : max_prod;
	
	do_weird_operation(matrix);						//eg. 123 456 789 -> 321 654 987 (so i can reuse the old check_diag function)
	max_prod_cand = check_diag(matrix);				//check diag, (right to left)
	max_prod = max_prod_cand > max_prod ? max_prod_cand : max_prod;
	
	cout << "max product is: " << max_prod << endl;
} 
