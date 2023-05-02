#include <stdio.h>
#include <time.h>

// mudar aqui em cima também dependendo de qual teste for querer fazer
//#define maxtam 5000
//#define maxtam 10000
//#define maxtam 15000
#define maxtam 20000

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        heapify(arr, i, 0);
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
  
  heapSort(arr, n);

  /*for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);*/
  
  clock_t end = clock();

  timespt += (double)(end - begin) / CLOCKS_PER_SEC;

  printf("tempo gasto: %lf\n", timespt);
}
