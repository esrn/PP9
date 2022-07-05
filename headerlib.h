#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void print_gaussian_dist (int expected_value, int std_deviation, int amount_of_values, FILE *output_stream) {


    double random1, random2, std_num1, ep, random_num;
    static double std_num2;
    static int staticvar = 0;

    if(staticvar==0) {
        do {
            random1 = ((double)rand() / RAND_MAX) * (2.0 - 0.0) - 1.0;
            random2 = ((double)rand() / RAND_MAX) * (2.0 - 0.0) - 1.0;
            ep = random1 * random1 + random2 * random2;
        } while(ep>=1.0);

        ep = sqrt((-2.0*log(ep)) / ep);
        std_num1 = random1*ep;
        std_num2 = random2*ep;
        staticvar=1;
    }
    else {
        std_num1 = std_num2;
        staticvar=0;
    }
    random_num = expected_value + std_deviation*std_num1;
    printf("%f \n",random_num); //testweise
    fprintf(output_stream, "%f \n",random_num);
    return;
}
