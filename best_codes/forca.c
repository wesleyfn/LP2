#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LETTERS 20

char ** toallocate(int, int);
void tofree(char **, int, int);
char ** enter_words(char **, int);
void prt_words(char **, int);
int menu(void);

int main(void)
{
    int n, i, case2op, case1op, menuop, flag = 0;
    char **word, hidew[LETTERS];

    do{
        menuop = menu();
        switch (menuop)
        {
        case 1:
            if (flag)
            {
                prt_words(word, n);
                printf("Choose:: ");
                scanf("%d", &case1op);
            }
            else
            {
                printf("\n-> Before adding words to the wordbase!\n\n");
            }
            break;
        case 2:
            printf("\n[1] Write words\n[2] Read words\n[3] Back\n:: ");
            scanf(" %d", &case2op);
            switch (case2op)
            {
            case 1:
                printf("\n-> Number of words: ");
                scanf(" %d", &n);
                word = toallocate(n, LETTERS);
                flag = 1;
                break;
            case 2:
                prt_words(word, n);
                break;
            case 3:
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    } while (menuop != 3);

    printf("\nPrograma finalizado!\n");
    return 0;
}

char ** toallocate(int l, int c)
{
    int i;
    char **mat;

    //Aloca um espaco na memoria
    mat = malloc(l * sizeof(char *));
    if (mat == NULL){
        puts("Erro de memoria!");
        exit(-1);
    }
    for (i = 0; i < l; i++)
    {
        mat[i] = malloc(c * sizeof(char));
        if (mat[i] == NULL){
            puts("Erro de memoria!");
            exit(-1);
        }
    }

    //Entrada das palavras
    mat = enter_words(mat, l);
    return mat;
}

void tofree(char **mat, int l, int c)
{
    //Libera o espaco de memoria alocado
    int i;
    for (i = 0; i < l; i++)
        free(mat[i]);
    free(mat);
    return;
}

char ** enter_words(char **mat, int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        printf("-> Word %d: ", i+1);
        scanf(" %[^\n]", mat[i]);
    }
    printf("\n");
    return mat;
}

void prt_words(char **mat, int l)
{
    int i;
    printf("\n");
    for (i = 0; i < l; i++)
        printf("/%d/::%s\n", i+1, mat[i]);
    printf("\n");
    return;
}

int menu(void)
{
    int op;
    printf("### Hangman Game! ###\n");
    printf("[1] Start\n[2] Wordbase\n[3] Exit\n");
    printf(":: ");
    scanf(" %d", &op);
    return op;
}