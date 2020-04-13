#include "tables.h"

// Prints tab for verification
void print_table(int * tab, int dim)
{
    int i;
    for(i=0;i<dim;i++) printf("%d ", *(tab+i));
}

// Fills histogram of tab
void histogram_table(int * tab, int dim, int * histogram)
{
    int i;
    
    for(i=0;i<maximum_table(tab, dim);i++) histogram[i]=0;
    
    for(i=0;i<dim;i++)
    {
        histogram[tab[i]]+=1;
    }
}

// Fills and writes histo to pgm file
void pgm_histogram(char * path, int * histo, int dim)
{
    int i;
    int * histogram_img;
    histogram_img = malloc(dim*(maximum_table(histo, dim)*sizeof(int)+1));
    
    for(i=0;i<dim*(maximum_table(histo, dim)+1);i++)
    {
        if(i/dim+1>=maximum_table(histo, dim)+1-histo[i%dim])
        {
            histogram_img[i]=dim;
        }
        else
        {
            histogram_img[i]=0;
        }
    }
    write_pgm(path, histogram_img, maximum_table(histo, dim), dim);
}

///

int maximum_table(int * tab, int dim)
{
    int maximum = tab[0], i;
    
    for(i=0;i<dim;i++)
    {
        if(maximum<tab[i]) maximum=tab[i];
    }
    
    return maximum;
}

int minimum_table(int * tab, int dim)
{
    int minimum = tab[0], i;
    
    for(i=0;i<dim;i++)
    {
        if(minimum>tab[i]) minimum=tab[i];
    }
    
    return minimum;
}

double mean_table(int * tab, int dim)
{
    int somme = 0, i;
    for(i=0;i<dim;i++)
    {
        somme+=tab[i];
    }
    return somme/dim;
}

double std_table(int * tab, int dim)
{
    int somme = 0, i, moyenne = mean_table(tab, dim);
    for(i=0;i<dim;i++)
    {
        somme+=(tab[i]-moyenne)*(tab[i]-moyenne);
    }
    return sqrt(somme/dim);
}
