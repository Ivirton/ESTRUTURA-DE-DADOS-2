#include <stdio.h>
#include <stdlib.h>
//https://youtu.be/vledOKDREnQ
//https://youtu.be/YKlDz1J3TSw
typedef struct node {
  int  valor;
  node *ant;
  node *prox;
} Node;
typedef struct list {
  node *cabeca_inicio ;
  node *cabeca_fim ;
  int  tamanho ;
} List;
void terminal(){
  system("cls");
}
list *alocarList(){
  list *nova = new list;
  nova->cabeca_inicio = NULL;
  nova->cabeca_fim = NULL;
  nova->tamanho = 0;
  return nova;
}
void print_list(list *list) {
  node *aux = list->cabeca_inicio;
  
  while (aux) {
    printf(" %d ->", aux->valor);
    aux = aux->prox;
  }
  printf(" NULL\n");
}
void adicionar(list *list,int valor){
  Node *novo_no = new Node;
  novo_no->valor = valor;
  novo_no->prox = list->cabeca_inicio;

  list->cabeca_inicio = novo_no;
  
 
}
int main() {
  terminal();
  List *lista1 = alocarList();  
  adicionar(lista1,4);
  adicionar(lista1,46);
  adicionar(lista1,48);
  adicionar(lista1,77);
  print_list(lista1);
  system("pause");
  return 0;
}