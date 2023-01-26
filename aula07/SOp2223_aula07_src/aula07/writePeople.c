#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    int i;
    int numPersons = 0;

    Person p = {35, 1.65, "xpto"};

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }



    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    printf("Quantas pessoas? ");
    scanf("%d", &numPersons);


    /* Write 10 itens on a file */
    for(i = 0 ; i < numPersons ; i++)
    {   
        printf("\nPessoa %d\n", i+1);
        printf("Nome? ");
        scanf(" %[^\n]",p.name);
        printf("Idade? ");
        scanf("%d", &p.age);
        printf("Altura? ");
        scanf("%lf", &p.height);

        fwrite(&p, sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
