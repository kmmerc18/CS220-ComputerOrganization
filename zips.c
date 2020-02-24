# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// struct (a structure)
typedef struct {
	char zip[6];	// 6 bytes
	char state[3];	// 3 bytes
	char *city;		// pointer is 4 bytes
	double lng;		// double is 8 bytes
	double lat;		// 8 bytes
} zipinfo; // name of the structure



/* parse_line extraxts zipcode info from a line and returns a pointer
 * to a zipinfo struct	*/



zipinfo *parse_line(char line[]) {
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
	i++;	
	zip[5] = '\0';
	//printf("zip // move past the comma	
	int j = 0;			
	while (line[i] != ',') {
	// extract the state
		state[j] = line[i];
		i++;
		j++;
	}
	state[2] = '\0';
	i++;
	//printf("state: %s\n", state);
	
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
	//printf("city: %s\n", city);
	
	
	// longitude
	i++;
	j = 0;
	char tmp_lng[10];
	while (line[i] != ',') {
		tmp_lng[j] = line[i];
		i++;
		j++;
	}
	tmp_lng[j] = '\0';
	// convert the string into a double
	lng = atof(tmp_lng);	// alpha to float (string to a double)
	//printf("longitude: %f\n", lng);
	
	// latitude
	i++;
	j = 0;
	char tmp_lat[10];
	while (line[i] != '\n') {
		tmp_lat[j] = line[i];
		i++;
		j++;
	}
	tmp_lat[j] = '\0';
	// convert the string into a double
	lat = atof(tmp_lat);	// alpha to float (string to a double)
	//printf("latitude: %f\n", lat);
	//free(city);
	
	
	
	// create a zipinfo struct and fill it wiht the data we just parsed
	zipinfo *info = malloc(sizeof(zipinfo));
	
	// copy the zipcode into the struct
	//strcpy((*info).zip, zip); or
	strcpy(info->zip, zip);
	strcpy(info->state, state);
	info-> city = city;
	
	info-> lat = lat;
	info-> lng = lng;
	
	return info;
}


// dump a zipinfo struct to the console
void print_zipinfo(zipinfo *info){
	// take the pointer to a zip info object and prints all of its stuff
	printf("zip code: %s\n", info->zip);
	printf("state: %s\n", info->state);
	printf("city: %s\n", info->city);
	printf("latitude: %.2f\n", info->lat);
	printf("longitude: %.2f\n", info->lng);
}

int main() {
	const int MAX_LINE_LEN = 1024;
	char buff[MAX_LINE_LEN];
	
	// declare an array of pointers to zipinfo structs
	zipinfo *ziparray[29470];		// number of zips in file
	int i = 0;
	
	while (fgets(buff, MAX_LINE_LEN, stdin) != NULL) {
		ziparray[i] = parse_line(buff);
		i++;
	}
	
	print_zipinfo(ziparray[--i]);
	
	//zipinfo *info = parse_line("35004,AL,ACMAR,86.51557,33.584132\n");
	//print_zipinfo(info);

	return 0;
}
