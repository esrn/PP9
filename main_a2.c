#include<stdio.h>
#include<getopt.h>
#include<gaussian_staticlib.h>

void help(){
	 printf("Bitte nutzen Sie folgende Argumente \n");
	 printf("-h: Hilfe \n");
 	 printf("-p: Angabe des Dateipfads \n");
}

int main(int argc, char* argv[]) {

	int opt;
	char *file;

	while((opt = getopt(argc, argv, "hp:" )) != -1){
		switch (opt){
			case 'h':
				help();
				return 0;
				break;
			case 'p':
				file = optarg;
				break;
		}
	}

	FILE *input_stream;
	input_stream = fopen(file,"r");

	if(input_stream == NULL){
		printf("Datei nicht vorhanden. \n");
		return 0;
	}
	
	printf("Statistik: \n");
	calc_gaussian_dist(input_stream);	
	fclose(input_stream);
	return 0;
}
