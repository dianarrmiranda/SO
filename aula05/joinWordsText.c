#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    char s[1024]="";

    for(i = 0 ; i < argc ; i++)
    {
        if(isalpha(argv[i][0])) //para não aparecer o primeiro argumento que é o nome do programa
        {
            strcat(s,argv[i]);
        }
    }

    printf("string : %s \n", s);

    return EXIT_SUCCESS;
}
