#include <stdio.h>
#include <time.h>

// mudar aqui em cima também dependendo de qual teste for querer fazer
//#define maxtam 5000
//#define maxtam 10000
//#define maxtam 15000
#define maxtam 20000

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
  FILE *arq;
  int arr[maxtam], num, i = 0;
  int n = sizeof(arr) / sizeof(arr[0]);
  double timespt = 0.0;

  // abrindo os arquivos de input de 5k de palavras, 10k, 15k e 20k

  //arq = fopen("input5.txt", "r");
  //arq = fopen("input10.txt", "r");
  //arq = fopen("input15.txt", "r");
  arq = fopen("input20.txt", "r");

  if (arq == NULL) {
    printf("erro ao abrir.\n");
    return 1;
  }
  while (fscanf(arq, "%i", &num) != EOF) {
    arr[i] = num;
    i++;
    // printf("%i\n", num);
  }

  clock_t begin = clock();
  
  insertionSort(arr, n);
  
  /*for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
  }*/

  clock_t end = clock();

  timespt += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("tempo gasto: %lf\n", timespt);
  
  return 0;
}
