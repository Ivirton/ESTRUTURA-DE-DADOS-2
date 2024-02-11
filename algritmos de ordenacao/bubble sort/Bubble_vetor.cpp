#include <stdio.h>
#include <stdlib.h>

void imprimir(int *vetor, int n);
void sort(int vetor[], int n);

int main() {
    int vetor[] = {4, 7, 5, 3, 6, 7, 4, 3};
   
    int size = sizeof(vetor) / sizeof(vetor[0]);
    printf("tamanho %d\n", size);
    imprimir(vetor, size);
    sort(vetor, size);
    imprimir(vetor, size);
    getchar();
    return 0;
}

void imprimir(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d,", vetor[i]);
    }
    printf("\n");
}

void sort(int vetor[], int n) {
    int aux = 0, trocas = 0, ultimo = n - 1;
    for (int i = 0; i < n-1; i++) {
        int trocou = 0;
        for (int j = 0; j < ultimo; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocas++;
                trocou = 1;
            }
            
        }
        if (!trocou) break;
        ultimo--;
    }
    printf("\ntrocas:%d\n", trocas);
}
