#include <stdio.h>
#include <stdlib.h>
#define QFILE 4

int main(void)
{
    int i, maq;
    char data_quant[20];
    FILE *file[QFILE];

    if ((file[0] = fopen("arq07.txt", "r")) == NULL){
        puts("Erro ao ler o arquivo!");
        return -1;
    }
    if ((file[1] = fopen("arq07-1.txt", "w")) == NULL){
        puts("Erro ao criar o arquivo!");
        return -1;
    }
    if ((file[2] = fopen("arq07-2.txt", "w")) == NULL){
        puts("Erro ao criar o arquivo!");
        return -1;
    }
    if ((file[3] = fopen("arq07-3.txt", "w")) == NULL){
        puts("Erro ao criar o arquivo!");
        return -1;
    }

    for ( ; !feof(file[0]) ; )
    {
        fscanf(file[0], "%d  ", &maq);
        fgets(data_quant, 20, file[0]);

        switch (maq)
        {
        case 1:
            fprintf(file[1], "%s", data_quant);
            break;
        case 2:
            fprintf(file[2], "%s", data_quant);
            break;
        case 3:
            fprintf(file[3], "%s", data_quant);
            break;                    
        default:
            break;
        }   
    }

    for (i = 0; i < QFILE; i++)
       fclose(file[i]);

    return 0;
}

