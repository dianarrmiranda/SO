#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compareStr(const void *a , const void *b)
{
    const void * ia = (const void *) a;
    const void * ib = (const void *) b;
    return strcmp(ia,ib); //Compara duas string caracter a caracter, se forem iguais retorna 0

}

int main(int argc, char *argv[])
{
    int i = 0;
    int maxsizeLine = 50;
    int index = argc-1;
    char array[index][maxsizeLine];

    /*fill in the array*/
    for( i=1 ; i<argc ; i++)
    {
        strcpy(array[i-1], argv[i]); //copia a string apontada pela origem para o destino strcpy(destination, source)
    }

    /*print unsorted array*/
    printf("\nUnsorted array:\n");
    for (int i = 0 ; i < argc-1 ; i++)
    {
        printf("%s\n",array[i]);
    }

    /*sort array*/
    qsort(array, index, maxsizeLine, compareStr); //dá sort de uma forma ascendente

    /*print sorted array*/
    printf("\nSorted array:\n");
    for (int i = 0 ; i < argc-1 ; i++)
    {
        printf("%s\n",array[i] );
    }

}
