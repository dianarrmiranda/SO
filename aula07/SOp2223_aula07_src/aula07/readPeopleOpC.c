#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>

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

    /*Get opts*/
    int opt;
    int bFlag=0, eFlag=0;
    int bVal=0, eVal=INT_MAX;

    while((opt=getopt(argc, argv, "b:e:")) != -1)
    {
        switch (opt) {
            case 'b':
                bFlag=1;
                bVal=atoi(optarg);
                break;
            case 'e':
                eFlag=1;
                eVal=atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage %s [-b begin_index] [-e end_index] filename\n" );
                exit(EXIT_FAILURE);
        }
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[optind], "rb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    printf("\n*--------People in file--------*\n" );
    int index=0;
    while(fread(&p, sizeof(Person), 1, fp) == 1)
    {
        if(index >= bVal && index <= eVal)
        {
            printPersonInfo(&p);
        }
        index++;
    }
    fclose(fp);


return EXIT_SUCCESS;
}