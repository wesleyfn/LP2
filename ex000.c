#include <stdio.h>

typedef struct{
    int nc;
    char titular[50];
    float saldo;
} TConta;

void mostra_menu(void);
void lista_contas(FILE *, int);
void le_conta(FILE *, TConta *);
void prn_conta(const TConta *);

int main()
{
    int op = 0;
    FILE *fp;

    if ((fp = fopen("contas.txt", "r")) == NULL){
        printf("Erro ao abrir arquivo!\n");
        return -1;
    }

    do{
        mostra_menu();
        scanf("%d", &op);
        switch(op){
            case 1: case 2: case 3:
                lista_contas(fp, op);
                break;
            case 0:
                break;
            default:
                printf("Opcao incorreta!\n");
                break;
        }
    } while (op != 4);

    fclose(fp);
    return 0;
}

void mostra_menu(void)
{
    printf("Digite a opcao:\n");
    printf("(1) Contas com saldo zero\n");
    printf("(2) Contas com saldo credor\n");
    printf("(3) Contas com saldo devedor\n");
    printf("(4) Encerrar programa\n");
}

void le_conta(FILE *f, TConta *ct)
{
    fscanf(f, "%d", &ct->nc);
    fscanf(f, "%s", ct->titular);
    fscanf(f, "%f", &ct->saldo);
}

void prn_conta(const TConta *ct)
{
    printf("%5d %-10s %-6.2f\n", ct->nc, ct->titular, ct->saldo);
}

void lista_contas(FILE *f, int op)
{
    TConta dados;
    char aux[255];

    rewind(f);
    fgets(aux, 255, f);
    printf("%s\n", aux);
    while(!feof(f)){
        le_conta(f, &dados);
        if (op == 1 && !dados.saldo)
            prn_conta(&dados);
        else if (op == 2 && dados.saldo > 0)
            prn_conta(&dados);
        else if (op == 3 && dados.saldo < 0)
            prn_conta(&dados);
    }
}