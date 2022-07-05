#include<stdio.h>
#include<math.h>
#include"gaussian_staticlib.h"

void calc_gaussian_dist(FILE *input_stream) {

	double expected_value;
	double std_deviation;
	double input_array[100];
	double input_sum;
	double std_deviation_sum;

	for(int i = 0; i<100; i++){
		fscanf(input_stream, "%lf, ", &input_array[i]);
	}

	for(int i = 0; i<100; i++){ 
		input_sum = input_sum + input_array[i];
	}
	expected_value = (input_sum / 100);
	for(int i = 0; i<100; i++){
		std_deviation_sum = std_deviation_sum + pow((input_array[i]-expected_value),2);
	}
	std_deviation = sqrt(std_deviation_sum/100);
	printf("Erwartungswert: %f \n",expected_value);
	printf("Standardabweichung: %f \n", std_deviation);
}
