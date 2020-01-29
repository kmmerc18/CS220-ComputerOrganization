#include <stdio.h>
int main() {
	double frequency = 1.4e9;	// 1.4 GHz
	
	// print cycle time to 12 decimal places
	printf("Cycle Time = %.12f\n", 1/frequency);

	// print cycle time in scientific notation
	printf("Cycle Time = %.2e\n", 1/frequency);
		
	// printf will choose whether or not to use scientific notation
	printf("Cycle Time = %g\n", 1/frequency);
		

}
