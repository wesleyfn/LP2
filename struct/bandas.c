#include <stdio.h>
#include <stdlib.h>
#define MAX 20 
#define NUM 2

typedef struct {
    char nome[MAX];
    char tipo[MAX];
    int quant;
    int ranking;
} Tbanda;

int main(void)
{
    Tbanda bandas[NUM];

    for (int i = 0; i < NUM; i++)
    {
        printf("Digite o nome: ");
        scanf(" %[^\n]", bandas[i].nome);
        printf("Digite o tipo musical: ");
        scanf(" %[^\n]", bandas[i].tipo);
        printf("Digite o numero de integrantes: ");
        scanf(" %d", &bandas[i].quant);
        printf("Digite o lugar no ranking: ");
        scanf(" %d", &bandas[i].ranking);
        printf("\n");
    }

    for (int i = 0; i < NUM; i++)
    {
        printf("Nome: %s\n", bandas[i].nome);
        printf("Tipo de musica: %s\n", bandas[i].tipo);
        printf("Numero de integrantes: %d\n", bandas[i].quant);
        printf("Ranking: %d\n", bandas[i].ranking);
    }

    return 0;
}