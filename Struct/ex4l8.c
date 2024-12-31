#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Vetor 
{
    double u;
    double x;
    double y;
    double z;
    double norma;
};

double calcula_norma(double u, double x, double y, double z)
{
    return sqrt((u * u) + (x * x) + (y * y) + (z * z));
}

int compara(const void *a, const void *b)
{
    struct Vetor *vetorA = (struct Vetor *)a;
    struct Vetor *vetorB = (struct Vetor *)b;

    if (vetorA->norma < vetorB->norma) return -1;
    if (vetorA->norma > vetorB->norma) return 1;
    return 0;
}

int main()
{
    int N, i;
    scanf("%d", &N);

    struct Vetor v[N];

    for (i = 0; i < N; i++)
    {
        scanf("%lf %lf %lf %lf", &v[i].u, &v[i].x, &v[i].y, &v[i].z);
        v[i].norma = calcula_norma(v[i].u, v[i].x, v[i].y, v[i].z);
    }

    qsort(v, N, sizeof(struct Vetor), compara);

    for (i = 0; i < N; i++)
    {
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", v[i].u, v[i].x, v[i].y, v[i].z, v[i].norma);
    }

    return 0;
}
