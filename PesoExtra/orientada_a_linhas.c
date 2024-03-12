#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *orientadaALinhas(int lin, int col, int n, int **A, int *x, int *b)
{
    for (lin = n - 1; lin >= 0; lin--)
    {
        x[lin] = b[lin];
        for (col = lin + 1; col < n; col++)
            x[lin] -= A[lin][col] * x[col];
        if (A[lin][lin] != 0)
        {
            x[lin] /= A[lin][lin];
        }
    }

    return x;
}

int main()
{
    srand(time(NULL));
    int lin, col, n;
    lin = col = n = 10;
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        A[i] = (int *)malloc(sizeof(int));
    }

    int *b = (int *)malloc(n * sizeof(int));
    int *x = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % n;
        }
    }

    for (int i = 0; i < n; i++)
    {
        b[i] = A[i][n - 1];
    }

    for (int i = 0; i < n; i++)
    {

        printf(" %i ", b[i]);
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %i ", A[i][j]);
        }

        printf("\n");
    }

    orientadaALinhas(n, n, n, A, x, b);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i ", x[i]);
    }
}