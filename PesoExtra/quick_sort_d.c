#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Implementação de algoritmo generico do quick sort para teste em relação ao count sort paralelizado
*/

#define MAX 10

void quick_sort(int *a, int left, int right);
int *geradorRandom(int seed, int qntd);
int main(int argc, char **argv)
{
    int i;
    clock_t start_time, end_time;
    int *v = geradorRandom(10000,1000000);
    

    start_time = clock();
    quick_sort(v, 0, 1000000);
    end_time = clock();

    double tempoPassado = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nTempo passado: %f", tempoPassado);

    return 0;
}

void quick_sort(int *a, int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < x && i < right)
        {
            i++;
        }
        while (a[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quick_sort(a, left, j);
    }
    if (i < right)
    {
        quick_sort(a, i, right);
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