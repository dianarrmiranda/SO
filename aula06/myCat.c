#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 80 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 

    /* Validate number of arguments */
    if( argc == 1  )
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* Open the file provided as argument */
    errno = 0;

    for(int i=0; i<argc-1; i++){
        fp = fopen(argv[i+1], "r");
        if( fp == NULL )
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        /* Read all the lines of the file */
        int j=1; int complete=1;

        while(fgets(line, sizeof(line), fp) != NULL )
        {
            if(complete){
                printf("%d -> ", j);
                j++;
            }

            printf("%s", line);  /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
            
            int linesize = strlen(line);

            if(linesize == LINEMAXSIZE-1 && line[linesize-1] != '\n'){
                complete = 0;
            }else
            {
                complete = 1;
            }

        }

        fclose(fp);

    }


    return EXIT_SUCCESS;
}
