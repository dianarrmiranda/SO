#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float a;
    float b;
    char *endarg;

    if (argc != 4)
    {
        printf("Número de argumentos inválido \n"); 
        return EXIT_FAILURE;

    }else{
        a = strtod(argv[1], &endarg);
        if(endarg == argv[1] || *endarg != '\0')
        //arg vazio             arg com numeros e letras   
        {
            printf("1º operando inválido. \n");
            return EXIT_FAILURE;
        }

        b = strtod(argv[3], &endarg);

        if(endarg == argv[3] || *endarg != '\0')
        {
            printf("2º operando inválido. \n");
            return EXIT_FAILURE;
        }
    }

/* Támbem funciona, mas a validação de argumentos com com strtod é mais correta
    float a = atof(argv[1]);

    float b = atof(argv[3]);

    if(a== 0 || b==0){
        printf("Número inválido \n"); 
        return EXIT_FAILURE;
    }

*/

    switch (*argv[2])
    {
    case '+':
        printf("%0.1f + %0.1f = %0.1f \n", a, b, a+b);
        break;
    case '-':
        printf("%0.1f - %0.1f = %0.1f \n", a, b, a-b);
        break;
    case 'x':
        printf("%0.1f x %0.1f = %0.1f \n", a, b, a*b);
        break;
    case '/':
        printf("%0.1f / %0.1f = %0.1f \n", a, b, a/b);
        break;
    case 'p':
        printf("%0.1f ^ %0.1f = %0.1f \n", a, b, pow(a, b));
        break;
    default:
        printf("Operador Inválido\n");
        break;
    }


    return EXIT_SUCCESS;
}
