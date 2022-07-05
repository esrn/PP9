#include<stdio.h>
#include<math.h>
//#include<unistd.h>
#include<getopt.h>
#include"headerlib.h"

void help() {
    printf("Bitte nutzen Sie folgende Argumente \n");
    printf("-h: Hilfe");
    printf("-e: Angabe des Erwartungswerts (ganzzahlig)");
    printf("-s: Angabe der Standardabweichung (ganzzahlig)");
    printf("-a: Angabe der Anzahl an Werten die generiert werden sollen (ganzzahlig)");
}


int main(int argc, char* argv[]) {

    int opt;
    int mu = 10;
    int sigma = 1;
    int amount_of_values = 110;

    while((opt = getopt(argc, argv, "he:s:a:" ))!= -1) {
        switch (opt) {
        case 'h':
            help();
            break;
        case 'e':
            mu = atoi(optarg);
            break;
        case 's':
            sigma = atoi(optarg);
            break;
        case 'a':
            amount_of_values = atoi(optarg);
            break;
        }
    }


    FILE *output_stream;
    output_stream = fopen("output_stream.txt","w");

    for(int i=0; i<amount_of_values; i++) {
        print_gaussian_dist(mu,sigma,amount_of_values,output_stream);
    }

    fclose(output_stream);
    return 0;
}
