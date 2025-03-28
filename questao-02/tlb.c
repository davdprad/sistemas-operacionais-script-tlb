#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define PAGESIZE 4096

long time_diff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000000L + (end->tv_usec - start->tv_usec);
}

int main(){

    char* filename = "tlb_resultados_q2.txt";
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    fprintf(file, "%-25s%-30s\n", "Número de Páginas", "Tempo Médio por Acesso (microssegundos)");

    int pages, qtd = 10000, size_vet, jump;
    // scanf("%d %d", &pages, &qtd);

    for(pages = 1; pages < 2000; pages++){
        printf("%d pages\n", pages);

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
        long tempo = time_diff(&inicio, &fim);
        float tempo_em_segundos = tempo / 1000000.0;
        float tempo_medio = tempo / qtd;
        // printf("Tempo medio decorrido: %f segundos.\n", tempo_medio);
        
        fprintf(file, "%-23d%-30f\n", pages, tempo_medio);

        free(vet);
    }

    fclose(file);

    printf("Testes concluidos. Resultados salvos em %s.\n", filename);
    
    return 0;
}