#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Count_sort(int a[], int n);

int main(int arch,char*argv []){
    int a[] = {1,56,12,1,7,9,0,234,2,33,3,12,5,7,823,1,234,24,5,55,76,12,34};
    for(int i = 0; i < 23; i++){
        printf(" %i ",a[i]);
    }    
    Count_sort(a,23);
    printf("\n\n");
    for(int i = 0; i < 23; i++){
        printf(" %i ",a[i]);
    } 
}

void Count_sort(int a[], int n) {
int i, j, count;
int* temp = malloc(n*sizeof(int));
for (i = 0; i < n; i++) {
count = 0;
for (j = 0; j < n; j++)
if (a[j] < a [i])
count++;
else if (a[j] == a[i] && j < i)
count++;
temp[count] = a[i];
}
memcpy(a, temp, n*sizeof(int));
free(temp);
}