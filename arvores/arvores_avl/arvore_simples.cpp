#include<stdio.h>
#include<stdlib.h>
typedef struct No{
    int valor;
    No *esquerda;
    No *direita;
    int altura;
}No;
    
int maior(int a,int b){
    //retorna o maior valor 
    return a > b ? a : b;
} 
int altura_no(No *no){
    //retorna a altura de um nó ou -1 caso ele seja null
    if(no == NULL){
        return -1;
    }else{
        return no->altura;
    }
}
int fator_balanceamento(No *no){
    //calcula e retorna o fator de balanceamento de um nó
    if(no){
        return(altura_no(no->esquerda) - altura_no(no->direita));
    }else return 0;
}
No* criarNo(int valor){
    No *novoNo = new No;
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->altura = 0;
    return novoNo;
}
void imprimir(No *node, int tab = 0) {
  if (node == NULL) return;

  imprimir(node->direita, tab + 1);
  for (int i = 0; i < tab; i++) {
    printf("\t");
  }
  printf("%d\n", node->valor);
  imprimir(node->esquerda, tab + 1);
}
void inserir(No **root,int valor){
    if(*root == NULL){
        *root = criarNo(valor);
    }else{
        if(valor < (*root)->valor)  inserir(&(*root)->esquerda,valor);   
        else inserir(&(*root)->direita,valor);   
    }
}
No *rotacao_esquerda(No *raiz){
    No *y,*f;
    y = raiz->direita;
    f = y->esquerda;

    y->esquerda = raiz;
    raiz->direita = f;
    //calcula a altura
    raiz->altura = maior(altura_no(raiz->esquerda),altura_no(raiz->direita)+1);
    y->altura = maior(altura_no(y->esquerda),altura_no(y->direita)+1);
    //retorna novo ó raiz
    return y;
}
No *rotacao_direita(No *raiz){
    No *y,*f;
    y = raiz->esquerda;
    f = y->direita;

    y->direita = raiz;
    raiz->esquerda = f;
    //calcula a altura
    raiz->altura = maior(altura_no(raiz->esquerda),altura_no(raiz->direita)+1);
    y->altura = maior(altura_no(y->esquerda),altura_no(y->direita)+1);
    //retorna novo ó raiz
    return y;
}
No *rotacao_diretia_esquerda(No *raiz){
    raiz->direita = rotacao_direita(raiz->direita);
    return rotacao_esquerda(raiz);
}
No *rotacao_esquerda_direita(No *raiz){
    raiz->esquerda = rotacao_esquerda(raiz->esquerda);
    return rotacao_direita(raiz);
}
int main(){
    system("cls");
    No *root = NULL;
    inserir(&root,200);
    inserir(&root,100);
    inserir(&root,150);
    imprimir(root);
    printf("\n");
    root = rotacao_esquerda_direita(root);
    imprimir(root);
    return 0;
}
