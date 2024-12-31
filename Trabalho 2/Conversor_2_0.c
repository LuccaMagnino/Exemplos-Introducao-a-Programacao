#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ler o arquivo Conversor.txt primeiro para obter informacoes!

//Funcao para converter unidades de tempo
void tempo(float te) 
{

    char *unidades[] = {"Segundos", "Minutos", "Horas"}; //String
    int num_unidades = 3; //Numero de unidades
    float *conversoes = (float *)malloc(num_unidades * sizeof(float));//Alocando memoria para conversoes
    //Padronizacao para segundos
    conversoes[0] = 1;
    conversoes[1] = 60;
    conversoes[2] = 3600;

    int x; // Define a escolha de unidade que possui
    printf("Qual a sua unidade de tempo?\n");

    //Loop para os indices da string "unidades"
    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &x);

    if (x < 1 || x > num_unidades) //Caso seja digitado um numero invalido
    {
        printf("Voce digitou um numero invalido\n");
        free(conversoes);
        return;
    }

    te *= conversoes[x - 1];

    int y; //Define a unidade que ira possuir
    printf("Voce quer converter para qual unidade?\n");

    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &y);

    if (y < 1 || y > num_unidades) 
    {
        printf("Voce digitou um numero invalido\n");
        free(conversoes);
        return;
    }
    //y ira definir a unidade e realizar a padronização para segundos
    te /= conversoes[y - 1];

    if (y == 2) 
    {
        //Caso nao seja um valor inteiro, ira definir o restante com a outra unidade, o mesmo para toda variavel "decimal"
        float decimal = (te - ((int)te)) * 60;
        printf("%d %s %d Segundos\n", (int)te, unidades[y - 1], (int)decimal);
    } 
    else if (y == 3) 
    {
        float decimal1 = (te - ((int)te)) * 60; 
        float decimal2 = (decimal1 - ((int)decimal1)) * 60;
        printf("%d %s %d Minutos %d Segundos\n", (int)te, unidades[y - 1], (int)decimal1, (int)decimal2);
    } 
    else 
    {
        printf("%.2f %s\n", te, unidades[y - 1]);
    }

    free(conversoes);
}

//Funcao para converter unidades de temperatura
void temperatura(float t) 
{
    char *unidades[] = {"Celsius", "Fahrenheit", "Kelvin"};//String
    int num_unidades = 3;//Numero de unidades

    int x;
    printf("Qual a sua unidade de temperatura?\n");
    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &x);

    if (x < 1 || x > num_unidades) 
    {
        printf("Voce digitou um numero invalido\n");
        return;
    }
    //Padronização para kelvin
    switch (x) 
    {
        case 1:
            t += 273.15;
            break;
        case 2:
            t = ((t - 32) / 1.8) + 273.15;
            break;
        case 3:
            break;
    }

    int y; 
    printf("Voce quer converter para qual unidade?\n");
    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &y);

    if (y < 1 || y > num_unidades) 
    {
        printf("Voce digitou um numero invalido\n");
        return;
    }

    switch (y) //Convertendo para a unidade desejada
    {
        case 1:
            t -= 273.15;
            printf("%.2f %s\n", t, unidades[y - 1]);
            break;
        case 2:
            t = (t * 1.8) - 459.67;
            printf("%.2f %s\n", t, unidades[y - 1]);
            break;
        case 3:
            printf("%.2f %s\n", t, unidades[y - 1]);
            break;
    }
}

//Funcao para converter unidades de distancia
void distancia(float d) 
{
    char *unidades[] = {"Metros", "Pes", "Jardas", "Polegadas"};//String
    int num_unidades = 4;//Numero de unidades
    float **conversoes = (float **)malloc(num_unidades * sizeof(float *)); //Alocacao para conversoes

    for (int i = 0; i < num_unidades; i++) 
    {
        conversoes[i] = (float *)malloc(num_unidades * sizeof(float));//Alocacao para as matrizes
    }

    // Conversao direta entre unidades
    conversoes[0][0] = 1;        // Metros para Metros
    conversoes[0][1] = 3.2808;   // Metros para Pes
    conversoes[0][2] = 1.0936133;// Metros para Jardas
    conversoes[0][3] = 39.3700787;// Metros para Polegadas

    conversoes[1][0] = 1 / 3.2808;   // Pes para Metros
    conversoes[1][1] = 1;        // Pes para Pes
    conversoes[1][2] = 1 / 3;    // Pes para Jardas
    conversoes[1][3] = 12;       // Pes para Polegadas

    conversoes[2][0] = 1 / 1.0936133; // Jardas para Metros
    conversoes[2][1] = 3;        // Jardas para Pes
    conversoes[2][2] = 1;        // Jardas para Jardas
    conversoes[2][3] = 36;       // Jardas para Polegadas

    conversoes[3][0] = 1 / 39.3700787; // Polegadas para Metros
    conversoes[3][1] = 1 / 12;    // Polegadas para Pes
    conversoes[3][2] = 1 / 36;    // Polegadas para Jardas
    conversoes[3][3] = 1;         // Polegadas para Polegadas

    int x;
    printf("Qual a sua unidade de distancia?\n");
    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &x);

    if (x < 1 || x > num_unidades) 
    {
        printf("Voce digitou um numero invalido\n");
        for (int i = 0; i < num_unidades; i++) 
        {
            free(conversoes[i]);
        }
        free(conversoes);
        return;
    }

    int y;
    printf("Voce quer converter para qual unidade?\n");
    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &y);

    if (y < 1 || y > num_unidades) 
    {
        printf("Voce digitou um numero invalido\n");
        for (int i = 0; i < num_unidades; i++) 
        {
            free(conversoes[i]);
        }
        free(conversoes);
        return;
    }
    //Chama as conversoes 
    d *= conversoes[x - 1][0];
    d /= conversoes[0][y - 1];

    printf("%.3f %s\n", d, unidades[y - 1]);

    for (int i = 0; i < num_unidades; i++) //Liberacao da memoria da matriz
    {
        free(conversoes[i]);
    }
    free(conversoes);
}

//Funcao para converter unidades de massa
void massa(float p) 
{
    char *unidades[] = {"Quilograma", "Libra", "Onca"};//String
    int num_unidades = 3;//Numero de unidades
    float *conversoes = (float *)malloc(num_unidades * sizeof(float));//Alocacao para conversoes

    //Padroniza para Kg
    conversoes[0] = 1;
    conversoes[1] = 0.453592;
    conversoes[2] = 0.0283495;

    int x;
    printf("Qual a sua unidade de massa?\n");
    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &x);

    if (x < 1 || x > num_unidades) 
    {
        printf("Voce digitou um numero invalido\n");
        free(conversoes);
        return;
    }

    p *= conversoes[x - 1];//Padroniza para Kg

    int y; 
    printf("Voce quer converter para qual unidade?\n");
    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &y);

    if (y < 1 || y > num_unidades) 
    {
        printf("Voce digitou um numero invalido\n");
        free(conversoes);
        return;
    }

    p /= conversoes[y - 1]; //Converte da padronizada para a desejada

    printf("%.4f %s\n", p, unidades[y - 1]);

    free(conversoes);
}

int main() {
    int l = 1; // realiza o loop
    float X;   // valor colocado pelo usuario
    int I1;    // Identificador
    while (l == 1) {
        printf("Qual medida voce deseja converter?\n Digite 1 para temperatura\n Digite 2 para distancia\n Digite 3 para massa\n Digite 4 para tempo\n");
        scanf("%d", &I1);

        printf("Qual o valor a ser utilizado?\n"); //valor definido pelo usuario para ser convertido
        scanf("%f", &X);

        switch (I1) {
            case 1: //funcao temperatura
                temperatura(X);
                break;
            case 2: //funcao distancia
                distancia(X);
                break;
            case 3: //funcao massa para conveter massa
                massa(X);
                break;
            case 4: //funcao tempo
                tempo(X);
                break;
            default:
                printf("Voce digitou um numero invalido\n");
                break;
        }

        printf("Voce deseja converter mais uma unidade?\n Digite 0 para nao\n Digite 1 para sim\n");
        //Caso seja digitado 1 o programa repete o loop de while, mas, caso seja digitado um numero diferente de 1, o programa termina.
        scanf("%d", &l);
    }
    return 0;
}

/*
Casos de teste:
Observacao: Ao final de cada saida deve ser colocado a entrada 1 para repetir a conversao, ao terminar os testes, basta digitar a entrada 0 para finalizar o programa

1-
Entrada:
1
36
1
2
Saida:
96.80 Fashrenheit

2-
Entrada:
2
100
1
4
Saida:
2.540 Polegadas

3-
3
85
1
3
Saida:
2998.2893 Onca

4-
4
50000
1
3
Saida:
13 Horas 53 Minutos 20 Segundos

*/
