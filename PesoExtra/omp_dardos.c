#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>

/* File:    omp_dardos.c

 * Compile: gcc -g -Wall -fopenmp -o omp_dardos omp_dardos.c
 * Usage:   ./omp_dardos <number of threads> <Numero de lançamentos>

 */
double Randoms();
void Usage(char *prog_name);
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int thread_count;
    double estimativa_de_pi = 0;
    long qnt_no_circulo = 0;
    double x, y, distancia_quadrada;
    thread_count = strtol(argv[1], NULL, 10);
    long total_lancamentos = strtol(argv[2], NULL, 10);
    ;
    /* printf("\nInsira o total de lancamentos: ");
    scanf("%li", &total_lancamentos); */
    int lancamento;

#pragma omp parallel num_threads(thread_count) \
    reduction(+ : qnt_no_circulo) private(y, x, distancia_quadrada, lancamento) shared(estimativa_de_pi) firstprivate(total_lancamentos) default(none)
    {
        total_lancamentos = total_lancamentos;
#pragma omp for schedule(static, 1)
        for (lancamento = 0; lancamento < total_lancamentos; lancamento++)
        {
            x = Randoms();
            y = Randoms();
            distancia_quadrada = (y * y) + (x * x);
            if (distancia_quadrada <= 1)
            {
                qnt_no_circulo++;
            }
        }
    }
    estimativa_de_pi = 4 * ((qnt_no_circulo) / ((double)total_lancamentos));
    printf("\nEstimativa de PI: %lf e a quantidade de dardos no circulo: %li", estimativa_de_pi, qnt_no_circulo);
}
void Usage(char *prog_name)
{

    fprintf(stderr, "usage: %s <number of threads> <number of terms>\n",
            prog_name);
    exit(0);
}

double Randoms()
{

    double num = ((double)(rand() / (RAND_MAX + 1.0))) - 1;

    return num;
}