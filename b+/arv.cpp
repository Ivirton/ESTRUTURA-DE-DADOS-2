#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct medicamento {
    int codigoBarras;
    char nome[50];
    char dataCadastro[20];
    int quantidade;
    float preco;
} medicamento;

typedef struct page {
    int qnt;
    int folha;
    int codigos[N - 1];
    struct page* pai;
    medicamento* medicamentos[N - 1];
    struct page* filhos[N];
    struct page* prox;
} pagina;

medicamento* criarMedicamento(int codigoBarras, char nome[50], char dataCadastro[20], int quantidade, float preco) {
  medicamento* novoMedicamento = new medicamento;
  novoMedicamento->codigoBarras = codigoBarras;
  strcpy(novoMedicamento->nome, nome);
  strcpy(novoMedicamento->dataCadastro, dataCadastro);
  novoMedicamento->quantidade = quantidade;
  novoMedicamento->preco = preco;
  return novoMedicamento;
}
pagina* criarPagina() {  
  pagina* novaPagina = new pagina;
  novaPagina->qnt = 0;
  novaPagina->folha = 1;
  novaPagina->pai = NULL;
  novaPagina->prox = NULL;
  return novaPagina;
}
medicamento* buscarMedicamento(pagina* raiz, int codigoBarras) {
    if (raiz == NULL) return NULL;
    pagina* temp = raiz;
    while (1) {
        int posicao;
        for (posicao = 0; posicao < temp->qnt; posicao++) {
            if (codigoBarras == temp->codigos[posicao]) return temp->medicamentos[posicao];
            if (codigoBarras < temp->codigos[posicao])  break;
        }
        if (temp->folha) return NULL;
        temp = temp->filhos[posicao];
    }
}
void inserirMedicamento(pagina*& raiz, medicamento* novoMedicamento) {
    if (raiz == NULL) {
      raiz = criarPagina();
      raiz->medicamentos[0] = novoMedicamento;
      raiz->codigos[0] = novoMedicamento->codigoBarras;
      raiz->qnt++;
      return;
    }
    pagina* temp = raiz;
    pagina* pai = NULL;
    while (!temp->folha) {
        pai = temp;
        int posicao;
        for (posicao = 0; posicao < temp->qnt; posicao++) {
            if (novoMedicamento->codigoBarras < temp->codigos[posicao]) break;
        }
        temp = temp->filhos[posicao];
    }
    int posicao;
    for (posicao = 0; posicao < temp->qnt; posicao++) {
        if (novoMedicamento->codigoBarras == temp->codigos[posicao]) {
          temp->medicamentos[posicao]->quantidade += novoMedicamento->quantidade;
          return;
        }
        if (novoMedicamento->codigoBarras < temp->codigos[posicao]) break;
    }
    for (int i = temp->qnt; i > posicao; i--) {
        temp->codigos[i] = temp->codigos[i - 1];
        temp->medicamentos[i] = temp->medicamentos[i - 1];
    }
    temp->codigos[posicao] = novoMedicamento->codigoBarras;
    temp->medicamentos[posicao] = novoMedicamento;
    temp->qnt++;
    if (temp->qnt == N) {
        pagina* novaPagina = criarPagina();
        novaPagina->pai = pai;
        for (int i = (N - 1) / 2 + 1; i < N - 1; i++) {
            novaPagina->codigos[i - ((N - 1) / 2 + 1)] = temp->codigos[i];
            novaPagina->medicamentos[i - ((N - 1) / 2 + 1)] = temp->medicamentos[i];
            novaPagina->filhos[i - ((N - 1) / 2 + 1)] = temp->filhos[i];
            novaPagina->qnt++;
            if (temp->filhos[i] != NULL) temp->filhos[i]->pai = novaPagina;
        }
        temp->qnt = (N - 1) / 2;
        novaPagina->folha = temp->folha;
        novaPagina->prox = temp->prox;
        temp->prox = novaPagina;
        inserirMedicamento(raiz, temp->medicamentos[temp->qnt]);
    }
}
void removerMedicamento(pagina*& raiz, int codigoBarras, int quantidade) {
  if (raiz == NULL) return;
  pagina* temp = raiz;
  while (1) {
    int posicao;
    for (posicao = 0; posicao < temp->qnt; posicao++) {
      if (codigoBarras == temp->codigos[posicao]) {
        temp->medicamentos[posicao]->quantidade -= quantidade;
        if (temp->medicamentos[posicao]->quantidade <= 0) {
          for (int i = posicao; i < temp->qnt - 1; i++){
            temp->codigos[i] = temp->codigos[i + 1];
            temp->medicamentos[i] = temp->medicamentos[i + 1];
          }
          temp->qnt--;
        }
        return;
      }      
    if (codigoBarras < temp->codigos[posicao])break;
    }
    if (temp->folha)return;
    temp = temp->filhos[posicao];
  }
}
void imprimirMedicamentos(pagina* raiz) {
  if (raiz == NULL) return;
  pagina* temp = raiz;
  while (!temp->folha) temp = temp->filhos[0];
  while (temp != NULL) {
    for (int i = 0; i < temp->qnt; i++) {
      printf("Ccdigo: %d\n", temp->codigos[i]);
      printf("Medicamento: %s\n", temp->medicamentos[i]->nome);
      printf("Data : %s\n", temp->medicamentos[i]->dataCadastro);
      printf("Quantidade: %d\n", temp->medicamentos[i]->quantidade);
      printf("Preco: %.2f\n", temp->medicamentos[i]->preco);
      printf("\n");
    }
    temp = temp->prox;
  }
}

int main() {
    pagina* raiz = NULL;
    
    // Inserir medicamentos
    medicamento* medicamento1 = criarMedicamento(12345, "Medicamento 1", "01/01/2023", 10, 19.99);
    medicamento* medicamento2 = criarMedicamento(54321, "Medicamento 2", "02/01/2023", 5, 9.99);
    medicamento* medicamento3 = criarMedicamento(98765, "Medicamento 3", "03/01/2023", 7, 15.99);
    inserirMedicamento(raiz, medicamento1);
    inserirMedicamento(raiz, medicamento2);
    inserirMedicamento(raiz, medicamento3);
    // Buscar medicamento pelo código de barras
    int codigoBarras = 54321;
    medicamento* medicamentoEncontrado = buscarMedicamento(raiz, codigoBarras);
    if (medicamentoEncontrado != NULL) {
        printf("Código de Barras: %d\n", medicamentoEncontrado->codigoBarras);
        printf("Nome do Medicamento: %s\n", medicamentoEncontrado->nome);
        printf("Data do Cadastro: %s\n", medicamentoEncontrado->dataCadastro);
        printf("Quantidade: %d\n", medicamentoEncontrado->quantidade);
        printf("Preço: %f\n", medicamentoEncontrado->preco);
    } else {
        printf("Medicamento não encontrado.\n");
    }
    // Remover medicamento
    int codigoBarrasRemocao = 12345;
    int quantidadeRemocao = 5;
    removerMedicamento(raiz, codigoBarrasRemocao, quantidadeRemocao);
    // Imprimir medicamentos ordenados pelo código de barras
    imprimirMedicamentos(raiz);
    system("pause");
    return 0;
}
