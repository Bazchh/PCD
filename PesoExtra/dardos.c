#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int Randoms();
int main()
{
    srand(time(NULL));
    long int total_lancamentos;
    double estimativa_de_pi = 0;
    long int qnt_no_circulo = 0;
    double x, y, distancia_quadrada;
    printf("\nInsira a quantidade total de lançamentos: ");
    scanf("%li", &total_lancamentos);

    for (int lancamento = 0; lancamento < total_lancamentos; lancamento++)
    {
        x = Randoms();
        y = Randoms();
        distancia_quadrada = (y * y) + (x * x);
        if (distancia_quadrada <= 1)
            qnt_no_circulo++;
    }
    estimativa_de_pi = 4 * qnt_no_circulo / ((double)total_lancamentos);

    printf("\nEstimativa de PI: %f e a quantidade de dardos no circulo: %li", estimativa_de_pi, qnt_no_circulo);
}

int Randoms()
{

    int num = (lrand48()%(2)) - 1 ;

    return num;
}