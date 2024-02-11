#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct cel {
  char nome[100];
  struct cel *prox;
} celula;

celula *cabeca = NULL;

celula *anterior(celula *cel) {
  if (cel == cabeca) {
    return NULL;
  }
  celula *ant = cabeca;
  while (ant != NULL) {
    if (ant->prox == cel) {
      return ant;
    }
    ant = ant->prox;
  }
  return NULL;
}
//retorna um ponteiro para a célula que precede a célula dada na lista.
void swap(celula *cel1, celula *cel2) {
  if ((cel1 == NULL) || (cel2 == NULL)) return;
  celula *ant1 = NULL;
  celula *ant2 = NULL;
  celula *tmp = NULL;
  if ((cabeca == cel2) || (cel2->prox == cel1)) {
    tmp = cel2;
    cel2 = cel1;
    cel1 = tmp;
  }

  if (cabeca != cel1) {
    ant1 = anterior(cel1);
  }

  ant2 = anterior(cel2);

  if (cel1 != cel2) {
    tmp = cel2->prox;

    if (ant1 != NULL) {
      ant1->prox = cel2;
    }

    if (cel1 != ant2) {
      ant2->prox = cel1;
      cel2->prox = cel1->prox;

      if (cel2->prox == cel1) {
        cel1->prox = cel2;
      } else {
        cel1->prox = tmp;
      }
    } else {
      cel2->prox = cel1;
      cel1->prox = tmp;
    }

    if (cabeca == cel1) {
      cabeca = cel2;
    }
  }
}
// troca as posições de duas células na lista. Se as células dadas são adjacentes, 
//elas são trocadas diretamente. Caso contrário, a função reordena os links das células para efetuar a troca.
void imprimir() {
  celula *aux = cabeca;
  int i = 0;
  while (aux != NULL) {
   
    i++;
    if (i > 10) {
      exit(0);
    }
    printf("%s -> ", aux->nome);
    aux = aux->prox;
  }
  printf("NULL\n");
}

celula *inserir_inicio(const char *n) {
  celula *nova = (celula *)malloc(sizeof(celula));
  strcpy(nova->nome, n);
  nova->prox = cabeca;
  cabeca = nova;
  return nova;
}

int length(celula *cabeca) {
  celula *aux = cabeca;
  int cont = 0;
  while (aux != NULL) {
    aux = aux->prox;
    cont++;
  }
  return cont;
}

celula *pos(int p) {
  celula *aux = cabeca;
  int cont = 0;
  while (aux != NULL) {
    if (cont == p) {
      return aux;
    }
    aux = aux->prox;
    cont++;
  }
  return NULL;
}

void shuffle() {
  int size = length(cabeca);
  for (int i = 0; i < size; i++) {
    celula *cel1 = pos(rand() % size);
    celula *cel2 = pos(rand() % size);
    swap(cel1, cel2);
  }
}

int main() {
  srand(time(NULL));
  celula *ultimo = inserir_inicio("Barbara");
  inserir_inicio("Harry");
  inserir_inicio("Carlos");
  inserir_inicio("Zidane");

  imprimir();
  shuffle();
  imprimir();

  return 0;
}
