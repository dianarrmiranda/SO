#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/

void listDir(char dirname[], int i)
{
    char path[1024];
    DIR *try;
    DIR *dp; 
    struct dirent *dent;

    dp = opendir(dirname); 
    if(dp == NULL)
    {
        perror("Error opening directory");
        return;
    }

    dent = readdir(dp);
    while(dent!=NULL) 
    {
        if(dent->d_name[0] != '.') /* do not list hidden dirs/files */
        {
            strcpy(path,"");
            strcat(path,dirname);
            strcat(path,"/");
            strcat(path, dent->d_name);
            try = opendir(path);

            if(try != NULL)
                printf("[d] %s\n",dent->d_name );
                if(i==2 && try != NULL)
                {
                printf("*--------%s--------*\n", path);
                listDir(path,2);
                }

            else
                printf("[f] %s\n",dent->d_name );

        }

        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }

    int i;

    printf("(1)Non-Recursive\n(2)Recursive\n> ");
    scanf("%i",&i);

    listDir(argv[1],i);
    
    return EXIT_SUCCESS;
}

