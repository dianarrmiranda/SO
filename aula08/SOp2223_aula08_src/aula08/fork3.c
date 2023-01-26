#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
                /*if (execl ("./child", "./child", NULL) < 0) { //Feito pelo filho
                perror ("erro no lancamento da aplicacao"); //Condição de erro -> nao será feita por ninguem*/
               if (execl ("/bin/ls", "ls","-l", NULL) < 0) { 
                  //$./ls -l . -> ls = argv[0] ; -l = argv[1]
                   perror ("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               printf("Porque é que eu não apareço?\n");
               //Porque o processo da child é terminado quando o exec termina!
               break;
      default: /* processo pai */
               sleep(1);
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    }

    return EXIT_SUCCESS;
}

/* b)
    i)Esta repetido, mas so aparentemnte. Nao e obrigatorio que esteja repetido! Especificamente, o programa child nao olha para o argv[0] !
  
    ii) $ ./child -> Quando fazemos ./ e feito um fork para guardar o codigo da shell, e depois um exec para executar o comando
        Se so quisessemos o exec: $ exec ./child -> Faz o exec no processo da bash mas quando o child temrinar o processo da bash vai tambem terminar
*/