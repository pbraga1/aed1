#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// mudar aqui em cima também dependendo de qual teste for querer fazer
//#define maxtam 5000
//#define maxtam 10000
//#define maxtam 15000
#define maxtam 20000

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
   
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
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
 
  /*for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);*/
 
  mergeSort(arr, 0, n - 1);
  
  /*for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);*/

  clock_t end = clock();

  timespt += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("tempo gasto: %lf\n", timespt);
  
  return 0;
}
