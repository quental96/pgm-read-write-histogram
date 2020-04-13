#ifndef tables_h
#define tables_h

#include "pgmfiles.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_table(int * tab, int dim);
void histogram_table(int * tab, int dim, int * histogram);
void pgm_histogram(char* path, int * histo, int dim);

///

int maximum_table(int * tab, int dim);
int minimum_table(int * tab, int dim);
double std_table(int * tab, int dim);
double mean_table(int * tab, int dim);

#endif
