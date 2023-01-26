#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    
    int last = atoi(argv[2]);
    int first = atoi(argv[1]);
    int secret;
    int numUser = 0;
    double d;

    //Escolha do número secreto
    d = (double) rand () / ((double) RAND_MAX + 1);
    int k = d * (last - first + 1);
    secret = first + k; 

    //Jogo
    while(numUser != secret){
        printf("Qual o número screto? ");
        scanf("%d", &numUser);

        if(numUser > secret){
            printf("\nMais baixo\n");
        }else if (numUser < secret){
            printf("\nMais alto\n");
        }
    }

    printf("\nAcertou!!\n");


    return EXIT_SUCCESS;
}


