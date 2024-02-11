#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cel {
  int num = 0;
  cel *ant = NULL;
  cel *prox = NULL;
} celula;

typedef struct list {
  celula *inicio = NULL;
  celula *fim = NULL;
  int tamanho = 0;
} lista;

void imprimir(lista *lst);
lista *merge(lista *lista1, lista *lista2);

void anexar_fim(lista *nova, lista *lista) {
  nova->tamanho += lista->tamanho;
  nova->fim->prox = lista->inicio;
  lista->inicio->ant = nova->fim;
  nova->fim = lista->fim;
}

void inserir_inicio(lista *lst, celula *elemento) {
  if ((lst == NULL) || (elemento == NULL)) {
    return;
  }

  if (lst->tamanho == 0) {
    lst->inicio = elemento;
    lst->fim = elemento;
    lst->tamanho = 1;
    elemento->ant = NULL;
    elemento->prox = NULL;
    return;
  }

  elemento->ant = NULL;
  elemento->prox = lst->inicio;
  lst->inicio->ant = elemento;
  lst->inicio = elemento;
  lst->tamanho++;
}

void inserir_fim(lista *lst, celula *elemento) {
  if ((lst == NULL) || (elemento == NULL)) {
    return;
  }

  if (lst->tamanho == 0) {
    lst->inicio = elemento;
    lst->fim = elemento;
    lst->tamanho = 1;
    elemento->ant = NULL;
    elemento->prox = NULL;
    return;
  }

  elemento->prox = NULL;
  elemento->ant = lst->fim;
  lst->fim->prox = elemento;
  lst->fim = elemento;
  lst->tamanho++;
}

void remover(lista *lst, celula *elemento) {
  if ((lst == NULL) || (elemento == NULL) || (lst->tamanho == 0)) {
    return;
  }

  if ((lst->inicio == elemento) && (lst->fim == elemento)) {
    lst->tamanho = 0;
    lst->inicio = NULL;
    lst->fim = NULL;
    return;
  }

  lst->tamanho--;

  if (lst->inicio == elemento) {
    lst->inicio = lst->inicio->prox;
    lst->inicio->ant = NULL;
    elemento->prox = NULL;
    return;
  }

  if (lst->fim == elemento) {
    lst->fim = lst->fim->ant;
    lst->fim->prox = NULL;
    elemento->ant = NULL;
    return;
  }

  celula *antElem = elemento->ant;
  celula *proxElem = elemento->prox;
  antElem->prox = proxElem;
  proxElem->ant = antElem;

  elemento->ant = NULL;
  elemento->prox = NULL;
}

lista *merge_sort(lista *lista1) {
  if ((lista1 == NULL) || (lista1->tamanho == 0)) {
    return NULL;
  }

  if (lista1->tamanho == 1) {
    return lista1;
  }

  lista *lista2 = new lista;
  int tam_metade = lista1->tamanho / 2;
  celula *inicio2 = lista1->inicio;
  for (int i = 0; i < tam_metade; i++) {
    inicio2 = inicio2->prox;
  }

  celula *fim1 = inicio2->ant;
  fim1->prox = NULL;
  inicio2->ant = NULL;

  lista2->inicio = inicio2;
  lista2->fim = lista1->fim;
  lista2->tamanho = lista1->tamanho - tam_metade;

  lista1->fim = fim1;
  lista1->tamanho = tam_metade;

  lista1 = merge_sort(lista1);

  lista2 = merge_sort(lista2);

  lista *res = merge(lista1, lista2);

  return res;
}

lista *merge(lista *lista1, lista *lista2) {
  if ((lista1 == NULL) && (lista2 == NULL)) {
    return NULL;
  }

  if ((lista1 != NULL) && (lista2 == NULL)) {
    return lista1;
  }

  if ((lista1 == NULL) && (lista2 != NULL)) {
    return lista2;
  }

  lista *nova = new lista;

  while ((lista1->tamanho > 0) && (lista2->tamanho > 0)) {
    int num1 = lista1->inicio->num;
    int num2 = lista2->inicio->num;
    celula *elemento;
    if (num1 < num2) {
      elemento = lista1->inicio;
      remover(lista1, elemento);
    } else {
      elemento = lista2->inicio;
      remover(lista2, elemento);
    }
    inserir_fim(nova, elemento);
  }
  if (lista1->tamanho > 0) {
    anexar_fim(nova, lista1);
  }

  if (lista2->tamanho > 0) {
    anexar_fim(nova, lista2);
  }

  return nova;
}

void gerar_aleatorios(lista *lst, int qnt) {
  celula *elem;
  for (int i = 0; i < qnt; i++) {
    elem = new celula;
    elem->num = rand() % 10;
    inserir_inicio(lst, elem);
  }
}

void imprimir(lista *lst) {
  if (lst == NULL) {
    return;
  }
  celula *aux = lst->inicio;
  while (aux != NULL) {
    printf("%d -> ", aux->num);
    aux = aux->prox;
  }
  printf("NULL\n");
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  lista *lst = new lista;
  gerar_aleatorios(lst, 10);
  imprimir(lst);
  lista *res = merge_sort(lst);
  imprimir(res);
  return 0;
}
