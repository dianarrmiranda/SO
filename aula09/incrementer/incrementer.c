/**
 * Incrementing a common integer variable with / without synchronization.
 * Thread implementation using primitives from the pthread library.
 *
 * Incrementing threads - inc = 0, 1, ... , N-1
 *
 * (c) 2004 Artur Pereira <artur@ua.pt>
 *
 *
 * Sintax: incrementer [options]
 */

//Código em que exemplifica o acesso de várias threads à mesma função partilhada, sem sincronização.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <pthread.h>

#include "incMod.h"

/* thread return status */
int status;

#define USAGE "Synopsis: %s [options]\n"\
    "\t----------+--------------------------------------------\n"\
    "\t  Option  |          Description                       \n"\
    "\t----------+--------------------------------------------\n"\
    "\t -i num   | number of increments                       \n"\
    "\t -t num   | number of 'threads' (<= 600)               \n"\
    "\t -h       | this help                                  \n"\
    "\t----------+--------------------------------------------\n"

/*   allusion to internal function */
static void *incrementer (void *arg);

/*   main thread: it starts the simulation and generates the incrementing threads
 */
int main (int argc, char *argv[])
{
    int niter = 1000;                                                                /* number of iterations by default */
    int nthr = 1;                                                                       /* number of threads by default */

    /* command line processing */
    const char *optstr = "i:t:h";                                                                    /* allowed options */
    int option;                                                                                        /* parsed option */

    do {
        switch ((option = getopt (argc, argv, optstr)))
        { 
          case 'i': niter = atoi (optarg);
                    break;
          case 't': nthr = atoi (optarg);
                    if (nthr > 600) {
                        fprintf (stderr, "Too many threads!\n");
                        fprintf (stderr, USAGE, basename (argv[0]));
                        return EXIT_FAILURE;
                    }
                    break;
          case 'h': printf (USAGE, basename(argv[0]));
                    return EXIT_SUCCESS;
          case -1:  break;
          default:  fprintf (stderr, "Non valid option!\n");
                    fprintf (stderr, USAGE, basename (argv[0]));
                    return EXIT_FAILURE;
        }
    } while (option >= 0);

    /* setting initial value of the common integer variable */
    vSet(0);

    /* launching the 'pthreads' */
    pthread_t thr[nthr];                                                             /* ids of the incrementing threads */
    int i;                                                                                         /* counting variable */
    int *status_p;                                                                /* pointer to thread execution status */

    printf ("Launching %d threads, each performing %d increments\n", nthr, niter);

    /* nthr representa o número de threads
       inicialmente é criado um array de pthreads que guarda o endereço
       de saída de cada thread
    */

    for (i = 0; i < nthr; i++) {
        /* O niter representa o numero de incrementos
           enquanto que o incrementar representa a rotina
           utilizada para incrementar a thread. Esta recebe
           como argumento o niter
        */
        if (pthread_create (thr+i, NULL, incrementer, &niter) != 0) { //A função pthread_create() é usada para criar um novo thread, com atributos especificados por attr, dentro de um processo.
            fprintf (stderr, "thread %d\n", i);                       //Se attr for NULL, os atributos padrão serão usados. 
            perror ("error on launching the thread");                 //Se os atributos especificados por attr forem modificados posteriormente, os atributos do thread não serão afetados. 
            return EXIT_FAILURE;                                      //Após a conclusão bem-sucedida, pthread_create() armazena o ID do encadeamento criado no local referenciado pelo encadeamento. 
        }
        //Se a pthread_create() for bem-sucedida, o valor retornado será 0. Caso contrário, um valor diferente de 0 será retornado.
    }

    /* wait for threads to conclude */
    for (i = 0; i < nthr; i++) { 
        if (pthread_join (thr[i], (void **) &status_p) != 0) {   //A função pthread_join() deve suspender a execução do thread de chamada até que o thread de destino termine, a menos que o thread de destino já tenha terminado. 
            fprintf (stderr, "thread %d\n", i);                   //No retorno de uma chamada pthread_join() bem-sucedida com um argumento value_ptr não NULL, o valor passado para pthread_exit() pelo thread finalizador deve ser disponibilizado no local referenciado por value_ptr. 
            perror ("error on waiting for a thread to conclude"); //Quando um pthread_join() retorna com sucesso, o thread de destino foi encerrado. 
            return EXIT_FAILURE;                                  //Os resultados de várias chamadas simultâneas para pthread_join() especificando o mesmo thread de destino são indefinidos. Se a thread chamando pthread_join() for cancelada, então a thread de destino não deve ser desconectada.
        }
        printf ("Thread %d has terminated: ", i);
        printf ("its status was %d\n", *status_p);
        //Se a pthread_join() for bem-sucedida, o valor retornado será 0. Caso contrário, um valor diferente de 0 será retornado.
    }

    /* print variable value and quit */
    printf ("Final value = %d\n", vGet());

    return EXIT_SUCCESS;
}


/*
 * thread routine
 */
void *incrementer (void *arg)
{
    int i, n;

    n = *((int *) arg);
    for (i = 0; i < n; i++) {
        vInc ();
    }

    status = EXIT_SUCCESS;
    pthread_exit (&status);
}

/*

Threads em C (biblioteca pthreads)

    int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

    * thread -> parametro de saida. Necessário passar o endereço de saída
    * attr -> geralmente passamos NULL
    * start_routine  ->
    * arg -> valor que vai ser passado à start start_routine

    Quando a thread começa invoca-se a start routine e passamos-lhe como parametro o arg
    Pthreads tem que returnar um void

    d)
        i)
            static int value; (Regia partilhada e manipulada por todas as threads!)
        
        ii)
            Seção de codigo que queremos que seja executada em exclusao mutua
            Neste caso vai corresponder as seccoes de codigo que vao retornar e alterar o value
            Na main NAO temos nenhuma regiao critica, mas nas funcoes do incMod temos uma em cada funcao

                value=new_value;

                return value;
                
                val=value;
                delay;
                value=value+1;
            ou seja, código de vSet, vGet, vInc
        iii)

            thread 1          thread 2

            vInc              vInc
            int val
          3 val = value
            delay        ->    int val
                             3 val = value
                               delay
                             4 value = value 3
          4 value=val+1 3 <-   delay  
            delay

        v) Se  fizermos 1000 in incrementos com N threads. Se N=2, o valor máximo é 2000 (nenhuma condição de corrida se verificou). 
           Por outro lado, o valor minimo é 1000 (porque umas das threads nao conseguiu incrementar). 
           Se N=10, o valor minimo será também 1000 (apenas 1 incrementou)
            
*/
