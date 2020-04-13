#include "pgmfiles.h"
#include "tables.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, const char * argv[]) {
    
    char * path = "/Users/quentintallon/Desktop/pgmProject/data/feep.pgm";
    int * tab;
    int * histogram;
    int dim;
    
    // Initialize PGM and get dimension of file
    printf("Initializing PGM.\n");
    dim = initialize_pgm(path);
    tab = malloc(dim*sizeof(int));
    printf("PGM dimension: %d \n", dim);
    
    // Stores PGM information in a table
    printf("Reading PGM.\n");
    read_pgm(path, tab);
    //print_table(tab, dim); printf("\n");
    
    // Creates a histogram of the table
    printf("Histogram creation.\n");
    histogram = malloc((maximum_table(tab, dim)+1)*sizeof(int));
    histogram_table(tab, dim, histogram);
    //print_table(histogram, maximum_table(tab, dim)+1); printf("\n");
    
    // Saves histogram in txt file
    printf("Saving histogram in text format.\n");
    write_table("/Users/quentintallon/Desktop/pgmProject/data/histogram.txt", histogram,
                maximum_table(tab, dim)+1);
       
    printf("Saving histogram in pgm format.\n");
    pgm_histogram("/Users/quentintallon/Desktop/pgmProject/data/histogram.pgm", histogram, maximum_table(tab, dim)+1);
     
    return 0;
}
