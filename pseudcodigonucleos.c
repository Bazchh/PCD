#include <stdio.h>

int somaGlobalNucleos(int arr[], int nucleo, int inicio, int fim, int deslocamento){
    int i, somaLocal = 0;
    for(i = inicio; i < fim; i+= deslocamento){
        somaLocal += arr[i];
    }
    return somaLocal;
}

int min(int a, int b){
    if(a <  b){
        return a;
    } else {
        return b;
    }
}


int main(){
    int arr[] = {1,2,5,7,2,10,9};
    int nucleos;
    printf("Insira a quantidade de nucleos: ");
    scanf("%i", &nucleos);

    int nPorp = 7/nucleos;
    int i = 0, somaTotal = 0, deslocamento = 1;
    if(7 % 2 != 0){
    deslocamento = 7 % nucleos;
    if(deslocamento == 0){
        deslocamento = 1;
    }
    }
    
    if(7 % 2 == 0){
        for(i = 0; i < nucleos; i++){
        somaTotal += somaGlobalNucleos(arr,i,nPorp*i,nPorp*(i+1),deslocamento);
        }
    } else {
        for(i = 0; i < nucleos; i++){
       somaTotal+= somaGlobalNucleos(arr,i,nPorp*(i)+(min(i, 7 % nucleos)),nPorp*(i+1)+(min(i+1, 7 % nucleos)),deslocamento);     
        }
    }

    printf("%i", somaTotal);

}