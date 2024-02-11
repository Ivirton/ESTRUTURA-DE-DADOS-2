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
  system("clear");
}
list *nova_lista(){
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
node *novo_node(int valor){
	node* novo = new node;
	novo->valor = valor;
	return novo;
}
node *buscar(List *list,int valor){
	node *aux = list->cabeca_inicio;
  while (aux) {
    if(aux->valor == valor){
			return aux;
		}
    aux = aux->prox;
  }
	return aux;
}
void adicionar(list *list,node *novo_no){
	if(list->cabeca_inicio == NULL || list->tamanho == 0){
		list->cabeca_fim = novo_no;
	}
  novo_no->prox = list->cabeca_inicio;
	novo_no->ant = NULL;
	if(list->cabeca_inicio != NULL){
		list->cabeca_inicio->ant = novo_no;
	}
  list->cabeca_inicio = novo_no;
  list->tamanho++;
 
}
int main() {
  terminal();
  List *lista1 = nova_lista();  
  adicionar(lista1,novo_node(5));
  adicionar(lista1,novo_node(6));
  adicionar(lista1,novo_node(3));
  adicionar(lista1,novo_node(9));
	// printf("inicio:%d\n",lista1->cabeca_inicio->valor);
	printf("fim:%d\n",lista1->cabeca_fim->valor);
  print_list(lista1);
	
	
  return 0;
}