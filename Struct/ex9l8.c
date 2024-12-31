#include <stdio.h>
#include <math.h>

struct Ponto4D 
{
    double u;
    double x;
    double y;
    double z;
};

double distancia(struct Ponto4D p1, struct Ponto4D p2) 
{
    double dist = sqrt(pow(p1.u - p2.u, 2) + 
                       pow(p1.x - p2.x, 2) +
                       pow(p1.y - p2.y, 2) +
                       pow(p1.z - p2.z, 2));
    return dist;
}

int main() 
{
    int N, i;
    scanf("%d", &N);

    struct Ponto4D pontos[N];

    for (i = 0; i < N; i++) 
    {
        scanf("%lf %lf %lf %lf", &pontos[i].u, &pontos[i].x, &pontos[i].y, &pontos[i].z);
    }


    for (i = 1; i < N; i++) 
    {
        double dist = distancia(pontos[i-1], pontos[i]);
        printf("%.2lf\n", dist);
    }

    return 0;
}

