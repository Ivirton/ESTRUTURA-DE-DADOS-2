#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertion_sort(int array[],int size){
    for(int i = 1; i < size; i++){
        int j = i-1;
        int aux = array[i];
        while (j>= 0 && array[j] > aux){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = aux;
    }
}
void imprimir(int *array,int size){
    for (int i = 0; i < size; i++)  printf(" %d ->",array[i]);
    printf(" \n");
}
int main() {
    int arr[] = {4, 7, 5, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

   printf("TAMANHO:%d\n",size);
    imprimir(arr, size);

    insertion_sort(arr, size);

    imprimir(arr, size);
    
    return 0;
}