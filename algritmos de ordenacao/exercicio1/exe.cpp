
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
typedef struct no {
  char nome[20];
  no *proximo;
} No;
void terminal(){
   system("cls");
}
int tamanho(no *head) {
  int tam = 0;
  while (head) {
    head = head->proximo;
    tam++;
  }
  printf("tamanho %d\n", tam);
  return tam;
}
no *create() {
  printf("Digite o nome:");
  no *novo = (no *)malloc(sizeof(no));
  scanf("%s", novo->nome);
  novo->proximo = NULL;
  return novo;
}
void adicionar(no **head, no *novo) {
  novo->proximo = *head;
  *head = novo;
}
void imprimir(no *head) {
  int tam = 0;
  while (head) {
    printf("%s -> ", head->nome);
    head = head->proximo;
    tam++;
  }
  printf("\n");
  printf("tamanho %d\n", tam);
  printf("\n-------------------\n");
}
int menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - NOVO ELEMENTO\t*\n");
  printf("*\t2 - IMPRIMIR LISTA\t*\n");
  printf("*\t3 - EMBARALHAR LISTA\t*\n");
  printf("*\t4 - ORD.BUBBLE SORT\t*\n");
  printf("*\t5 - ORD.SELECTION SORT\t*\n");
  printf("*\t6 - ORD.INSECTION SORT\t*\n");
  printf("*\t0 - SAIR\t\t*\n >");
  int valor = 0;
  scanf("%d", &valor);
 terminal();
  return valor;
}

void troca(no *no1,no*no2){
  no *temp = no1;
  no1 = no2;
  no2 = temp;
}


void bubbleSort(no **head) {
  if (*head == NULL || (*head)->proximo == NULL) return; // Verifica se a lista está vazia ou tem apenas um elemento
  int trocas;
  No* atual;
  No* proximo;
  No* inicio = NULL;

  do {
    trocas = 0;
    atual = *head;
    while (atual->proximo != inicio) {
      proximo = atual->proximo;
      if (strcmp(atual->nome, proximo->nome) > 0) {
        char temp[20];
        strcpy(temp, atual->nome);
        strcpy(atual->nome, proximo->nome);
        strcpy(proximo->nome, temp);
        trocas++;
      }
      atual = atual->proximo;
    }
    inicio = atual;
  } while (trocas > 0);
}


int main() {
  
  no *head = NULL;
  int op = 0;
  terminal();
  do {
    op = menu();
    imprimir(head);
    switch (op) {
    case 1:
      adicionar(&head, create());
      terminal();
      imprimir(head);
      break;
    case 2:
      imprimir(head);
      break;
    case 3:
      break;
    case 4:
			bubbleSort(&head);
      terminal();
      break;
    case 5:
      break;
    }
  } while (op != 0);
  return 0;
}