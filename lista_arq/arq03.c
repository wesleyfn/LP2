#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[25], matricula[10];
    char sexo, email[50];
    int idade;
} TAluno;

void setAlunoFile(FILE *, TAluno *);

int main(void)
{
    int i, n;
    TAluno aluno;
    FILE *file;

    if ((file = fopen("arq03.txt", "w")) == NULL){
        puts("Erro ao criar o arquivo!");
        return -1;
    }

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);
    getchar(); //pega o '\n' para não ir ao fgets

    printf("\n");
    for (i = 0; i < n; i++)
    {   
        printf("Digite o nome: ");
        scanf(" %s", aluno.nome);
        
        printf("Digite a matricula: ");
        scanf(" %s", aluno.matricula);

        printf("Digite a matricula [M/F]: ");
        scanf(" %c", &aluno.sexo);

        printf("Digite a idade: ");
        scanf(" %d", &aluno.idade);

        printf("Digite o email: ");
        scanf("%s", aluno.email);
        printf("\n");

        setAlunoFile(file, &aluno);
    }
    
    fclose(file);
    return 0;
}

void setAlunoFile(FILE *f, TAluno *a)
{
    fprintf(f, "%-28s", a->nome);
    fprintf(f, "%-13s", a->matricula);
    fprintf(f, "%-6c", a->sexo);
    fprintf(f, "%-6d", a->idade);
    fprintf(f, "%s\n", a->email);
    return;
}