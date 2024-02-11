#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct no{
    char caracter;
    no* proximo;
}No;


void adicionar(no **head,char letra){
    no *novo = (no *)malloc(sizeof(no));
    novo->caracter = letra;
    novo->proximo = *head;
    *head = novo;
}
void imprimir(no *head) {
  while (head) {
    printf("%c -> ", head->caracter);
    head = head->proximo;
  }
  printf(" NULL \n");

}
void imprimir(char *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c,", vetor[i]);
    }
    printf("\n");
}
void sort(char *vetor, int n) {
    int trocas = 0, ultimo = n - 1;
    for (int i = 0; i < n-1; i++) {
        int trocou = 0;
        for (int j = 0; j < ultimo; j++) {
            if(strcmp(&vetor[j],&vetor[j+1]) > 0){
                char aux = vetor[j];
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
void bubbleSort(No **head) {
  if (*head == NULL || (*head)->proximo == NULL) {
    return;
  }
  int trocas = 0;
  No *atual, *proximo, *inicio = NULL;
  do {
    trocas = 0;
    atual = *head;
    while (atual->proximo != inicio) {
      proximo = atual->proximo;
      if (atual->caracter > proximo->caracter) {
        char temp = atual->caracter;
        atual->caracter = proximo->caracter;
        proximo->caracter = temp;
        trocas++;
      }
      atual = atual->proximo;
    }
    inicio = atual;
  } while (trocas > 0);
}
int main() {
     
     no *head = NULL;
     adicionar(&head,'f');
     adicionar(&head,'g');
     adicionar(&head,'a');
     adicionar(&head,'h');
     imprimir(head);
     bubbleSort(&head);
    imprimir(head);
     
     //char nomes[] = {'c', 'b', 'd', 'f', 'a', 'g', 'e', 'h'};
    // int size = sizeof(nomes) / sizeof(nomes[0]);
    // printf("tamanho %d\n", size);
    // imprimir(nomes, size);
    // sort(nomes, size);
    // imprimir(nomes, size);
    getchar();
    return 0;
}