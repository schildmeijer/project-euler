#include <iostream>

int main (int argc, char * const argv[]) {
   

//	Find the sum of all the multiples of 3 or 5 below 1000.
	std::size_t sum = 0;
	for (int i = 3; i < 1000; ++i ) {
		if (i % 3 && i % 5)
			continue;
		sum += i;
		std::cout << i << std::endl;
			
	}
	
	std::cout << "sum: " << sum << std::endl;
    return 0;
}
