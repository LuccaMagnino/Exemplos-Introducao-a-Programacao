#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data 
{
    int dia;
    int mes;
    int ano;
};

struct Aluno 
{
    int matricula;
    struct Data data_nasc;
    char nome[201];
};

int ComparaDataNasc(struct Data data1, struct Data data2) 
{
    if (data1.ano < data2.ano)
    {
        return 1;
    }
    else if (data1.ano > data2.ano)
    {
        return 0;
    }
    else 
    {
        if (data1.mes < data2.mes)
        {
            return 1;
        }
        else if (data1.mes > data2.mes)
        {
            return 0;
        }
        else 
        {
            if (data1.dia <= data2.dia)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}


void OrdenaAlunos(struct Aluno alunos[], int n) {

    int i, j;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (!ComparaDataNasc(alunos[j].data_nasc, alunos[j + 1].data_nasc)) 
            {
                struct Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n, i;
    scanf("%d", &n);

    struct Aluno alunos[n];

    for (i = 0; i < n; i++) 
    {
        scanf("%d %d %d %d ", &alunos[i].matricula,
                               &alunos[i].data_nasc.dia,
                               &alunos[i].data_nasc.mes,
                               &alunos[i].data_nasc.ano);
        fgets(alunos[i].nome, 200, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
    }

    OrdenaAlunos(alunos, n);

    for (i = 0; i < n; i++)
    {
        printf("Matric.: %d Nome: %s Data Nasc.: %d/%d/%d\n",
            alunos[i].matricula, alunos[i].nome,
            alunos[i].data_nasc.dia, alunos[i].data_nasc.mes, alunos[i].data_nasc.ano);
    }

    return 0;
}