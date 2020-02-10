#include <stdio.h>

int main() {
		short int x = 0xFFFF;	// -1 (shorts are signed)
		int y = 0xFFFF;			// 2^16 -1
		int z = 0xFFFFFFF;		// 2^28 -1
		int z_1 = 0xFFFFFFFF;	// -1
		int a = 1000000000;		// scientific numbers are doubles
		int b = 2000000000;
		int c = a + b;
		
		printf("%d\n", c);
		
		// 67 - 23
		int d = 67 + (~23 + 1);
		printf("%d\n", d);
		
		// print the location of variable d
		// & - address of
		printf("%x\n", &d);
		
		return 0;
}
