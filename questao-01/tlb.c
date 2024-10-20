#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define PAGESIZE 4096

long time_diff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000000L + (end->tv_usec - start->tv_usec);
}

int main(){
    int pages, qtd, size_vet, jump;
    scanf("%d %d", &pages, &qtd);

    jump = PAGESIZE / sizeof(int);

    size_vet = (pages*PAGESIZE) / sizeof(int);

    int *vet = (int *)malloc(size_vet * sizeof(int));

    if (vet == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for(int i = 0; i < size_vet; i++){
        vet[i] = 0;
    }

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    for(int iter = 0; iter < qtd; iter++){
        for(int i = 0; i < size_vet; i += jump){
            vet[i] += 1;
        }
    }

    gettimeofday(&fim, NULL);
    long tempo = time_diff(&inicio, &fim); // Em microssegundos
    float tempo_medio = tempo / qtd;
    printf("Tempo medio decorrido: %f microssegundos.\n", tempo_medio);

    free(vet);
    
    return 0;
}