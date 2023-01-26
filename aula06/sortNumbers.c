#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/
#define LINEMAXSIZE 80

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{
    int i, numSize;
    int *numbers;
    int count = 0;  // Line counter (result)
    char c;

    FILE *fp;

    fp = fopen(argv[1], "r");

    if( fp == NULL )
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    }

    char line [count]; 


    numSize = sizeof(line);

    /* Memory allocation for all the numbers in the arguments */
    numbers = (int *) malloc(sizeof(int) * numSize);
    i=0;
    while(fgets(line, sizeof(line), fp) != NULL )
    {
        /* Storing the arguments in the "array" numbers */
        numbers[i] = atoi(line);
        i++;

    }

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for(i = 0 ; i < numSize ; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}
