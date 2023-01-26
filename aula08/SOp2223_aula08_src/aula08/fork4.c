#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int stat;

    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
               if (execl("./child", "./child", NULL) < 0) { 
                   perror("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               break;
      default: /* processo pai */
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
               if (wait(&stat) < 0) { 
                   perror("erro na espera da terminação do processo-filho");
                   return EXIT_FAILURE;
               }
               printf("Pai: o processo-filho terminou. ");
               if (WIFEXITED(stat) != 0) {
                   printf("O seu status de saída foi %d.\n", WEXITSTATUS(stat));
               }
               else {
                   printf("O processo filho terminou de forma anormal.\n");
               }
    }

    return EXIT_SUCCESS;
}

/* 
    4) a) 
        A chamada de sistema wait() suspende a execução do processo de chamada até que um de seus filhos termine. 
        A chamada wait(&status) é equivalente a: waitpid(-1, &status, 0); 
        A chamada de sistema waitpid() suspende a execução do processo de chamada até que um filho especificado pelo argumento pid tenha mudado de estado.

        b)
            i) As modificações relativamente ao fork3.c são:
                - Inclusão da biblioteca <sys/wait.h>
                - Declaração da variável stat
                - Inclusão da chamada wait(&stat) e da sua verificação
                - Inclusão da chamada WIFEXITED(stat) e da sua verificação
                - Inclusão da chamada WEXITSTATUS(stat) e da sua verificação
                Ou seja, o pai espera que o filho termine e verifica se o filho terminou de forma anormal ou não.
    */
