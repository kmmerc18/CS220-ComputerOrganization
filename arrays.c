#include <stdio.h>

// global variable
// It is visible in all functions. Do not  use them!
// Unless Harcourt says so
int a_global_variable;

void f(char chs[], int n) {
	
	// n is the size of the array
	// arrays are passed by reference (not by value)
	chs[0] = ';';
}

int main() {

	// variables defined inside of a function are called local variables
	int vec[10];		// array of ten integers
	
	for (int i = 0; i < 10; i++) {
		printf("%d\n", vec[i]);
	}

	// Array index out of bounds
	// printf("%d\n", vec[10000]);
	
	char symbols[] = {'!', '#', '&', '%', '\''};
	char syms[] = "!#&%\'";		// same as above, short hand notation
	// c has no string, a string is an array of characters

	for (int i = 0; i < 5; i++) {
		printf("%c\n", symbols[i]);
	}

	f(symbols, 5);
	printf("%c\n", symbols[0]);
}