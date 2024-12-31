#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Curso 
{
    int cod;
    double valor;
    char *nome;
};

struct Aluno 
{
    char *nome;
    int cod_curso;
    int creditos;
};

int main() 
{
    int i, j;
    int n; 
    scanf("%d", &n);

    struct Curso *cursos = (struct Curso *) malloc(n * sizeof(struct Curso));

    for (i = 0; i < n; i++) 
    {
        scanf("%d", &cursos[i].cod);
        scanf("%lf", &cursos[i].valor);

        char buffer[1001];
        getchar(); 
        fgets(buffer, 1000, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        cursos[i].nome = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(cursos[i].nome, buffer);
    }

    int m;
    scanf("%d", &m);

    struct Aluno *alunos = (struct Aluno *) malloc(m * sizeof(struct Aluno));

    for (i = 0; i < m; i++) 
    {
        char buffer[1001];
        getchar();
        fgets(buffer, 1000, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        alunos[i].nome = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(alunos[i].nome, buffer);

        scanf("%d", &alunos[i].cod_curso);
        scanf("%d", &alunos[i].creditos);
    }

    for (i = 0; i < m; i++) 
    {
        struct Curso *curso = NULL;

        for (j = 0; j < n; j++) 
        {
            if (alunos[i].cod_curso == cursos[j].cod) 
            {
                curso = &cursos[j];
                break;
            }
        }
        if (curso != NULL) 
        {
            double mensalidade = alunos[i].creditos * curso->valor;

            printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n",
                alunos[i].nome, curso->nome, alunos[i].creditos, curso->valor, mensalidade);
        }
    }

    for (i = 0; i < n; i++) 
    {
        free(cursos[i].nome);
    }
    free(cursos);

    for (i = 0; i < m; i++) 
    {
        free(alunos[i].nome);
    }
    free(alunos);

    return 0;
}
