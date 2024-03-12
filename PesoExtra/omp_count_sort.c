#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>
void Count_sort(int *a, int n, int threads);
int *geradorRandom(int seed, int qntd);
/* File:    omp_count_sort.c

 * Compile: gcc -g -Wall -fopenmp -o omp_cts omp_count_sort.c
 * Usage:   ./omp_cts <number of threads>

 */

int main(int arch, char *argv[])
{
    clock_t start_time, end_time;
    int *v = geradorRandom(10000,1000000);
    /* for (int i = 0; i < 23; i++)
    {
        printf(" %i ", a[i]);
    } */

    int numero_de_threads = strtol(argv[1], NULL, 10);
    start_time = clock();
    Count_sort(v, 1000000, numero_de_threads);
    end_time = clock();

    double tempoPassado = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nTempo passado: %f", tempoPassado);

    /*  printf("\n\n");
     for (int i = 0; i < 23; i++)
     {
         printf(" %i ", a[i]);
     } */
}

void Count_sort(int *a, int n, int threads)
{
    int i, j, count;
    int *temp = malloc(n * sizeof(int));
#pragma omp parallel num_threads(threads) private(i, j, count) shared(temp)
    {
#pragma omp for
        for (i = 0; i < n; i++)
        {
            count = 0;

            for (j = 0; j < n; j++)
            {

                if (a[j] < a[i])
                    count++;
                else if (a[j] == a[i] && j < i)
                    count++;
            }
            temp[count] = a[i];
        }
#pragma omp single
        {
            memcpy(a, temp, n * sizeof(int));
            free(temp);
        }
    }
}


int *geradorRandom(int seed, int qntd)
{
    int i = 0;
    srand(seed);
    int *vetor = (int *)malloc(qntd * sizeof(int));
    for (i = 0; i < qntd; i++)
    {
        vetor[i] = rand() % qntd;
    }
    return vetor;
}
/*
a) as variaveis que devem ser privadas para cada nucleo são as variaveis i, j e count, assim cada thread vai pegar sua parte do array ao dividir o array a entre si
alterando somente os valores aos quais ele foi designado para realizar as comparações, dessa forma, mesmo que as threads acessem a variavel temp ao mesmo tempo, como estarão
alterando partes diferentes do vetor temp, não há condição de corrida ou indeterminismo
*/

/*
b)
Não haverá dependencia de dados, devido ao fato de que as threads não necessitam extritamente dos valores resultados por outras threads para o vetor a ser ordenado
pois cada thread vai trabalhar apenas em uma parte especifica do vetor e alterar somente posições no temp com base na quantidade de valores menores da posição a qual está sendo comparada com as demais
 */

/*
c) Sim, é possivel. Mas temos que definir essa região como uma região que deve ser executada por uma unica thread, já que se multiplas threads realizarem essa chamada de função
haverá um indeterminismo de dados, além de que estaremos perdendo recurso computacional executando uma escrita na memoria várias e várias vezes, a depender do numero de threads que estão sendo utilizadas

 */

/*
Questão D é o codigo implementado
 */

/* 
O quick sort mesmo em sua forma sequencial consegue ser melhor que o count sort em sua forma paralelizada
Alguns dos testes realizados com o quick sort com os valores de 1000, 10000, 100000 e 1000000 de valores em um vetor definidos aleatoriamente: 


quick sort 

com 1000:
Tempo passado: 0.000000
com 10000:
Tempo passado: 0.000000
com 100000: 
Tempo passado: 0.013000
com 1000000: 
Tempo passado: 0.123000


count sort
com 1000:
Tempo passado: 0.001000
com 10000:
Tempo passado: 0.109000
com 100000: 
Tempo passado: 11.181000
com 1000000: 
Tempo passado: ////
com 1000000 de valores para o count sort eu não obtive um valor. O programa continuou rodando por cerca de mais de 10 minutos e não acabou
Desse modo, podemos ver que o quick sort mesmo em implementação sequencial é muito melhor que o count sort


 */
