#include "pgmfiles.h"

// Returns dim of PGM and verifies file opening
int initialize_pgm(char file_name[])
{
    int M, H, W;
    char type[2];
    FILE *f;
    
    f = fopen(file_name,"r");
    
    if (f==NULL) printf("Cannot open file: %s", file_name);
    
    fscanf(f, "%s %d %d %d", type, &W, &H, &M);
    
    return H*W;
}

// Reads PGM and stores it in tab
void read_pgm(char file_name[], int * tab)
{
    int i;
    int M, H, W;
    char type[2];
    FILE *f;
    
    f=fopen(file_name,"r");
    
    if (f==NULL) printf("Cannot open file: %s", file_name);
    
    fscanf(f,"%s %d %d %d", type, &W,&H,&M);

    for (i=0;i<H*W;i++) fscanf(f, "%d", &tab[i]);
    
    if (fclose(f)!=0) printf("Cannot close file: %s", file_name);
    
    return;
}

// Writes tab to txt file
void write_table(char file_name[], int tab[], int dim)
{
    int i;
    FILE *f;
    
    f=fopen(file_name,"w");
    
    
    if (f==NULL) printf("Cannot open file: %s", file_name);
    
    for(i=0;i<dim;i++) fprintf(f, "%d\n", *(tab+i));
    
    if (fclose(f)!=0) printf("Cannot close file: %s", file_name);
}

// Writes tab to pgm file
void write_pgm(char file_name[], int tab[], int H, int W)
{
    int i;
    FILE *f;
    
    f=fopen(file_name,"w");
    
    if (f==NULL) printf("Cannot open file: %s", file_name);

    fprintf(f,"P2\n%d %d\n%d\n",W,H, maximum_table(tab, H*W));
    
    for (i=0;i<H*W;i++) fprintf(f,"%d ",tab[i]);

    if (fclose(f)!=0) printf("Cannot close file: %s", file_name);

    return;
}

