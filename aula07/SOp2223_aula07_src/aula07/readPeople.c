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

int main (int argc, char **argv)
{
    FILE *fp = NULL;
    Person p;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    printf("\n*--------People in file--------*\n" );
    while(fread(&p, sizeof(Person), 1, fp) == 1)
    {
        printPersonInfo(&p);
    }
    fclose(fp);

    /*Add new people*/
    int op;
    printf("Do you wish to add new people?\n(1)Yes\n(2)No\n> ");
    scanf("%i",&op );

    if(op==1)
    {
        errno = 0;
        fp = fopen(argv[1], "ab");
        if(fp == NULL)
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        /*Ask for number of people*/
        int numPeople;
        printf("Number of people: " );
        scanf("%i", &numPeople);


        /* Write 10 itens on a file */
        for(int i = 0 ; i < numPeople ; i++)
        {
            Person p;
            printf("\nName: " );
            scanf("%s[^\n]%*c",p.name );
            printf("Age: " );
            scanf("%i",&p.age );
            printf("Height: " );

            scanf("%lf",&p.height );

            fwrite(&p, sizeof(Person), 1, fp);
        }

        fclose(fp);
    }

    return EXIT_SUCCESS;
}