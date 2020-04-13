#ifndef pgmfiles_h
#define pgmfiles_h

#include "tables.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int initialize_pgm(char file_name[]);
void read_pgm(char file_name[],  int * tab);
void write_table(char file_name[], int tab[], int dim);
void write_pgm(char file_name[], int tab[], int H, int W);

#endif
