#include <stdio.h>
#include <stdlib.h>

struct cel {
    int chave;
    struct cel* esq;
    struct cel* dir;
};

struct cel* criar(int chave){
    struct cel* novoNo = (struct cel*)malloc(sizeof(struct cel));
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

struct cel* inserir(struct cel* raiz, int chave){
    if (raiz == NULL){
        return criar(chave);
    }
    if (chave < raiz->chave){
        raiz->esq = inserir(raiz->esq, chave);
    }
    else if (chave > raiz->chave){
        raiz->dir = inserir(raiz->dir, chave);
    }
    return raiz;
}

void prefixo(struct cel* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->chave);
        prefixo(raiz->esq);
        prefixo(raiz->dir);
    }
}

void infixo(struct cel* raiz){
    if (raiz != NULL){
        infixo(raiz->esq);
        printf("%d ", raiz->chave);
        infixo(raiz->dir);
    }
}

void posfixo(struct cel* raiz){
    if (raiz != NULL){
        posfixo(raiz->esq);
        posfixo(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

void liberar(struct cel* raiz){
    if (raiz != NULL){
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main() {
    int C;
    scanf("%d", &C);
    
    for(int i = 1; i <= C; i++){
        int N;
        scanf("%d", &N);
        
        struct cel* raiz = NULL;
        for (int j = 0; j < N; j++){
            int num;
            scanf("%d", &num);
            raiz = inserir(raiz, num);
        }
    printf("Case %d:\n", i);
    printf("Pre.: ");
    prefixo(raiz);
    printf("\n");
        
    printf("In..: ");
    infixo(raiz);
    printf("\n");
        
    printf("Post:");
    posfixo(raiz);
    printf("\n");
        
    liberar(raiz);
    printf("\n");
    }
 
    return 0;
}
