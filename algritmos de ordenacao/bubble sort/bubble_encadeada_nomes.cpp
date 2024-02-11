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
int tamanho(no *head) {
  int tam = 0;
  while (head) {
    head = head->proximo;
    tam++;
  }
//printf("tamanho %d\n", tam);
  return tam;
}
void bubble_sort(No** head) {
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
no *pos(int p) {
  no *aux = cabeca;
  int cont = 0;
  while (aux != NULL) {
    if (cont == p) {
      return aux;
    }
    aux = aux->proximo;
    cont++;
  }
  return NULL;
}
//retorna um ponteiro para a célula que precede a célula dada na lista.
no *anterior(no *cel) {
  if (cel == cabeca) {
    return NULL;
  }
  no *ant = cabeca;
  while (ant != NULL) {
    if (ant->proximo == cel) {
      return ant;
    }
    ant = ant->proximo;
  }
  return NULL;
}
void swap(no *cel1, no *cel2) {
  if ((cel1 == NULL) || (cel2 == NULL)) return;
  no *ant1 = NULL, *ant2 = NULL, *tmp = NULL;
  if ((cabeca == cel2) || (cel2->proximo == cel1)) {
    tmp = cel2;
    cel2 = cel1;
    cel1 = tmp;
  }
  if(cabeca != cel1)ant1 = anterior(cel1);
  ant2 = anterior(cel2);
  if(cel1 != cel2){
    tmp = cel2->proximo;
    if(ant1 != NULL) ant1->proximo = cel2;
    if(cel1 != ant2){
      ant2->proximo = cel1;
      cel2->proximo = cel1->proximo;
      if (cel2->proximo == cel1) cel1->proximo = cel2;
      else cel1->proximo = tmp;
    }else{
      cel2->proximo = cel1;
      cel1->proximo = tmp;
    }
    if (cabeca == cel1) cabeca = cel2;
  }
}
void shuffle() {
  int size = tamanho(cabeca);
  for (int i = 0; i < size; i++) {
    no *cel1 = pos(rand() % size);
    no *cel2 = pos(rand() % size);
    swap(cel1, cel2);
  }
}
int main() {
  clear_screen();
  adicionar(&cabeca, "ivirton");
  adicionar(&cabeca, "pedro");
  adicionar(&cabeca, "alberto");
  adicionar(&cabeca, "jose");
  imprimir(cabeca);
  bubble_sort(&cabeca);
  imprimir(cabeca);
  shuffle();
  imprimir(cabeca);
  return 0;
}
