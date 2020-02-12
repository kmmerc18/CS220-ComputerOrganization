# include <string.h>	// strlen
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc 

int main() {
	int i = 12345;
	int *j = &i;			// j is a pointer to an integer
	
	printf("%d\n", i);
	printf("0x%x\n", j);

	*j = 88;				// follow the pointer, makes i = 88
	printf("%d\n", i);
	
	// *j is an alias of i
	// an alias is another name for a variable or a storage area
	
	// j = 0;					// segmentation fault (crash, you suck)
	// *j = 12345;				// definitely not allowed
	
	char *str;
	
	// allocate memory for the string
	// str[0] = 'h';
	char *tmp = "Hello world";	// a C string constant (array of bytes)
	str = malloc(strlen(tmp));	// allocate however many bytes tmp is 
	
	
	char *saved = str;
	// copy tmp in to str
	while (*tmp != '\0'){
		*str = *tmp;
		str++;					// advance the pointers to next byte
		tmp++;
	}
	
	*str = '\0';
	printf("DEBUG %s\n", saved);
}
