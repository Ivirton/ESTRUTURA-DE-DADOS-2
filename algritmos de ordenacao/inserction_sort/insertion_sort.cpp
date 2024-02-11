#include <stdio.h>

void move(int *vetor, int start, int end) {
  for (int p = end; p > start; p--) {
    vetor[p] = vetor[p - 1];
  }
}

void insertion_sort() {
  int vetor[] = {9, 7, 5, 7, 3, 2, 8};
  int n = 7;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (vetor[i] <= vetor[j]) {
        int tmp = vetor[i];
        move(vetor, j, i);
        vetor[j] = tmp;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("-> %d", vetor[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  insertion_sort();
  return 0;
}
