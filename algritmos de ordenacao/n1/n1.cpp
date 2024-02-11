#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct  ingressos{
    char nome_comprador[20];
    char cpf[11];
    char data_evento[10];
    ingressos *proximo;
}Ingressos;
typedef struct lista{
    ingressos *cabeça;
    ingressos *fim;
    int tamanho;
}Lista;
ingressos *novoIngresso(char *cpf,char *nome, char *data){
    Ingressos *novo = new Ingressos;
    strcpy(novo->cpf,cpf);
    strcpy(novo->nome_comprador,nome);
    strcpy(novo->data_evento,nome);
    return novo;
}
void adicionar(){

}
int main(){
    
    return 0;
}
