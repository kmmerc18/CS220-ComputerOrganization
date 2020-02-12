# include <stdio.h>

void parse_line(char line[]) {
	char zip[6];			// leave room for the null character
	char state[3];
	char *city;
	double lat, lng;		// latitude and longitude
	
	// extract the zip code
	int i = 0;
	while (line[i] != ',') {
		zip[i] = line[i];
		i++;
	}
	
	zip[5] = '\0';
	printf("zip code: %s\n", zip);		// DEBUG
	
	// extract the state
	i++;					// move past the comma	
	int j = 0;			
	while (line[i] != ',') {
		state[j] = line[i];
		i++;
		j++;
	}
	state[2] = '\0';
	printf("state: %s\n", state);
	
	// extract the city
	i++;
	j = 0;
	while (line[i] != ',') {
		city[j] = line[i];
		i++;
		j++;
	}
	city[] = '\0';
	printf("state: %s\n", state);
	
}

int main() {
	parse_line("35004,AL,ACMAR,86.51557,33.584132");


	return 0;
}
