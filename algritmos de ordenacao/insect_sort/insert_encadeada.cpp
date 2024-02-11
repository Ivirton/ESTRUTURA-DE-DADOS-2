#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no {
  char nome[20];
  struct no* proximo;
} No;
No* cabeca = NULL;
void clear_screen() {
  system("cls");
}
void imprimir(No* head) {
  while (head) {
    printf("%s -> ", head->nome);
    head = head->proximo;
  }
  printf("NULL\n");
}
void adicionar(No** head, char* nome) {
  No* novo = (No*)malloc(sizeof(No));
  if (novo == NULL) {
    printf("Erro ao alocar memoria\n");
    exit(1);
  }
  strcpy(novo->nome, nome);
  novo->proximo = *head;
  *head = novo;
}
void insertionSort(no** head) {
    no* i = *head;
    while (i != NULL) {
        no* j = i;
        while (j->proximo != NULL && strcmp(j->proximo->nome, i->nome) < 0) {
            j = j->proximo;
        }
        if (j != i) {
            no* curr = i;
            i = i->proximo;
            curr->proximo = j->proximo;
            j->proximo = curr;
        } else {
            i = i->proximo;
        }
    }
}

int main() {
  clear_screen();
  adicionar(&cabeca, "ivirton");
  adicionar(&cabeca, "pedro");
  adicionar(&cabeca, "alberto");
  adicionar(&cabeca, "jose");
  imprimir(cabeca);
  insertionSort(&cabeca);
  imprimir(cabeca);
  
  
  return 0;
}
