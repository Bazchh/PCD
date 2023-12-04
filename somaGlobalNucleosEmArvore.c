#include <stdio.h>

nucleosEmArvore(int arr[], int nNucleos, int nucleoAtual,int inicio, int fim, int deslocamento, int div, int count){
    int i, somaLocal = 0;
    for(i = inicio; i < fim; i+= deslocamento){
        somaLocal+= arr[i];
    }
    count++;
    if(nucleoAtual < nNucleos && count < div){
        somaLocal += nucleosEmArvore(arr, nNucleos, nucleoAtual+1,(16/nNucleos)*(nucleoAtual+1),(16/nNucleos)*((nucleoAtual+1)+1),deslocamento,div,count);
    }

    return somaLocal;
}

int min(int a, int b){
    if(a < b){
        return a;
    }  else {
        return b;
    }
}


int main(){
    int arr[] = {6,2,1,6,7,9,11,23,67,8,1,0,10,92,15,17}, qntNucleos = 8, i, deslocamento = 1, somaTotal = 0;
    int nPorp = 16/qntNucleos;
    int divDeNucleos = (qntNucleos)/(qntNucleos/2);

    if(16%2 == 0){
        for(i = 0; i < qntNucleos; i+= divDeNucleos){
            somaTotal += nucleosEmArvore(arr,qntNucleos,i,nPorp*i,nPorp*(i+1),deslocamento,divDeNucleos, 0);
        }
    }

    printf("%d", somaTotal);
}