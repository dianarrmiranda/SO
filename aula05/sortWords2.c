#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compareStr(const void *a , const void *b)
{
    const void * ia = (const void *) a;
    const void * ib = (const void *) b;
    return strcmp(ia,ib); //Compara duas string caracter a caracter, se forem iguais retorna 0

}

int main(void)
{
    int i = 0;
    int maxsizeLine = 50;
    char array[i][maxsizeLine];
    char s;

    printf("String? ");
    scanf("%s", &s);
    /*fill the array*/
    while(s != "0"){

        strcpy(array[i], s);
        printf("String? ");
        scanf("%s", &s);

    }

    /*print unsorted array*/
    printf("\nUnsorted array:\n");
    for (int i = 0 ; i < sizeof(array) ; i++)
    {
        printf("%s\n",array[i]);
    }

    /*sort array*/
    qsort(array, i, maxsizeLine, compareStr); //dá sort de uma forma ascendente

    /*print sorted array*/
    printf("\nSorted array:\n");
    for (int i = 0 ; i < sizeof(array) ; i++)
    {
        printf("%s\n",array[i] );
    }

}
