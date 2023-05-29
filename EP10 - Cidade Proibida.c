#include <stdio.h>
#include <stdbool.h>

#define infinito 9999
#define max_n 1000

// achar vertice com menor distancia
int distanciamin(int dist[], bool visitado[], int numNo){
  int min = infinito, minIndex;
  for (int i = 0; i < numNo; i++){
    if (!visitado[i] && dist[i] <= min){
      min = dist[i];
      minIndex = i;
    }
  }
  return minIndex;
}

// solução mais curta

void imprimirsolucao(int dist[], int parent[], int comeco, int destino){
  printf("%d\n", dist[destino] + 1);
}

// dijkstra

void dijkstra(int graph[max_n][max_n], int comeco, int destino, int avoidc, int numNo){
  int dist[max_n];
  bool visitado[max_n];
  int parent[max_n];

  for (int i = 0; i < numNo; i++){
    dist[i] = infinito;
    visitado[i] = false;
  }

  dist[comeco] = 0;
  parent[comeco] = -1;

  for (int cont = 0; cont < numNo - 1; cont++){
    int u = distanciamin(dist, visitado, numNo);
    visitado[u] = true;

    for (int v = 0; v < numNo; v++){
      if (!visitado[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v] && (u != avoidc || v != avoidc)){
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
      }
    }
  }
  imprimirsolucao(dist, parent, comeco, destino);
}

int main() {
  int graph[max_n][max_n], numNo, numRotas;
  int Curytyba, RiachodeFevereiro, Estadunido;

  while (scanf("%d %d", &numNo, &numRotas) == 2){
    for (int i = 0; i < numNo; i++){
      for (int j = 0; j < numNo; j++){
        graph[i][j] = 0;
      }
    }

    for (int i = 0; i < numRotas; i++){
      int cidA, cidB;
      scanf("%d %d", &cidA, &cidB);
      graph[cidA-1][cidB-1] = 1;
      graph[cidB-1][cidA-1] = 1;
    }

    scanf("%d %d %d", &Curytyba, &RiachodeFevereiro, &Estadunido);
    Curytyba--;
    RiachodeFevereiro--;
    Estadunido--;

    dijkstra(graph, Curytyba, RiachodeFevereiro, Estadunido, numNo);
  }

  
  return 0;
}
