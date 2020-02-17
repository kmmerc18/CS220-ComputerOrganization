# include <stdio.h>
# include <stdlib.h>

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
	printf("zip code: %s\n", zip);	// DEBUG
	
	// extract the state
	i++;			// move past the comma	
	int j = 0;			
	while (line[i] != ',') {
		state[j] = line[i];
		i++;
		j++;
	}
	state[2] = '\0';
	printf("state: %s\n", state);
	
	// count the characters between the commas
	int city_len = 0;
	j = i;
	while (line[j] != ',') {
		city_len++;
		j++;
	}
	
	// extract the city
	// load the city into the city variable
	city = malloc(city_len + 1);	// like new in Java
	j = 0;
	char *temp_city = city;
	while (line[i] != ',') {
		// could have done city[i];
		*temp_city = line[i];
		temp_city++;	// increment the pointer so it points to the next location
		i++;
	}
	*temp_city = '\0';
	printf("city: %s\n", city);
	
	
	// longitude
	i++;
	j = 0;
	char tmp_lng[11];
	while (line[i] != ',') {
		tmp_lng[j] = line[i];
		i++;
		j++;
	}
	tmp_lng[j] = '\0';
	// convert the string into a double
	lng = atof(tmp_lng);	// alpha to float (string to a double)
	printf("longitude: %f\n", lng);
	
	// latitude
	i++;
	j = 0;
	char tmp_lat[11];
	while (line[i] != '\n') {
		tmp_lat[j] = line[i];
		i++;
		j++;
	}
	tmp_lat[j] = '\0';
	// convert the string into a double
	lat = atof(tmp_lat);	// alpha to float (string to a double)
	printf("latitude: %f\n", lat);
	free(city);
}

int main() {
	// parse_line("35004,AL,ACMAR,86.51557,33.584132\n");
	
	const int MAX_LINE_LEN = 1024;
	char buff[MAX_LINE_LEN];
	
	while (fgets(buff, MAX_LINE_LEN, stdin) != NULL) {
		parse_line(buff);
	}

	return 0;
}
