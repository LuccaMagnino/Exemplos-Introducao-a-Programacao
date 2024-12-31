#include <stdio.h>
#include <string.h>

struct Curso {
    int cod;
    double valor;
    char nome[101];
};

struct Aluno {
    char nome[501];
    int cod;
    int cred;
};

int main() {
    int n, i, j;
    scanf("%d", &n);
    struct Curso cursos[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &cursos[i].cod);
        scanf("%lf", &cursos[i].valor);
        getchar(); 
        fgets(cursos[i].nome, 101, stdin);
        cursos[i].nome[strcspn(cursos[i].nome, "\n")] = '\0';
    }

    int m;
    scanf("%d", &m);
    struct Aluno alunos[m];

    for (i = 0; i < m; i++) {
        getchar(); 
        fgets(alunos[i].nome, 501, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        scanf("%d", &alunos[i].cod);
        scanf("%d", &alunos[i].cred);
    }


    for (i = 0; i < m; i++) {
        struct Curso *curso = NULL;

        for (j = 0; j < n; j++) {
            if (alunos[i].cod == cursos[j].cod) {
                curso = &cursos[j];
                break;
            }
        }

        if (curso != NULL) {
            double mensalidade = alunos[i].cred * curso->valor;
            printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2lf Mensalidade: %.2lf\n",
                   alunos[i].nome, curso->nome, alunos[i].cred, curso->valor, mensalidade);
        }
    }

    return 0;
}
