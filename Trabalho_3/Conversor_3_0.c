#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicao da struct para armazenar as conversoes
typedef struct 
{
    char tipo[20];
    float valorOriginal;
    char unidadeOriginal[20];
    float valorConvertido;
    char unidadeConvertida[20];
} Conversao;

// Funcao para salvar conversoes em arquivo
void salvarConversao(Conversao *conversoes, int n) 
{
    FILE *arquivo = fopen("conversoes.txt", "w");
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for (int i = 0; i < n; i++) 
    {
        fprintf(arquivo, "%s %.2f %s %.2f %s\n", conversoes[i].tipo,
         conversoes[i].valorOriginal, conversoes[i].unidadeOriginal, 
         conversoes[i].valorConvertido, conversoes[i].unidadeConvertida);
    }
    fclose(arquivo);
}

// Funcao para carregar conversoes de arquivo
void carregarConversoes(Conversao *conversoes, int *n) 
{
    FILE *arquivo = fopen("conversoes.txt", "r");
    if (arquivo == NULL) 
    {
        printf("Nenhum dado anterior encontrado!\n");
        return;
    }
    *n = 0;
    while (fscanf(arquivo, "%s %f %s %f %s", conversoes[*n].tipo,
     &conversoes[*n].valorOriginal, conversoes[*n].unidadeOriginal, &conversoes[*n].valorConvertido, 
     conversoes[*n].unidadeConvertida) != EOF) 
    {
        (*n)++;
    }
    fclose(arquivo);
}

// Funcao para converter unidades de tempo
void tempo(float te) 
{
    char *unidades[] = {"Segundos", "Minutos", "Horas"}; // String
    int num_unidades = 3; // Numero de unidades
    float *conversoes = (float *)malloc(num_unidades * sizeof(float)); // Alocando memoria para conversoes

    // Padronizacao para segundos
    conversoes[0] = 1;
    conversoes[1] = 60;
    conversoes[2] = 3600;

    int x; // Define a escolha de unidade que possui
    printf("Qual a sua unidade de tempo?\n");
    for (int i = 0; i < num_unidades; i++) 
    {
        printf("Digite %d para %s\n", i + 1, unidades[i]);
    }
    scanf("%d", &x);

    // Caso seja digitado um numero invalido
    if (x < 1 || x > num_unidades) 
    {
        printf("Voce digitou um numero invalido\n");
        free(conversoes);
        return;
    }

    te *= conversoes[x - 1];

    int y; // Define a unidade que ira possuir
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
    // y ira definir a unidade e realizar a padronizacao para segundos
    te /= conversoes[y - 1];

    if (y == 2) 
    {
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

// Funcao para converter unidades de temperatura
void temperatura(float t) 
{
    char *unidades[] = {"Celsius", "Fahrenheit", "Kelvin"}; // String
    int num_unidades = 3; // Numero de unidades

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
    // Padronizacao para Kelvin
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

    switch (y) 
    { // Convertendo para a unidade desejada
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

// Funcao para converter unidades de distancia
void distancia(float d) 
{
    char *unidades[] = {"Metros", "Pes", "Jardas", "Polegadas"}; // String
    int num_unidades = 4; // Numero de unidades
    float **conversoes = (float **)malloc(num_unidades * sizeof(float *)); // Alocacao para conversoes

    for (int i = 0; i < num_unidades; i++) 
    {
        conversoes[i] = (float *)malloc(num_unidades * sizeof(float)); // Alocacao para as matrizes
    }

    // Conversao direta entre unidades
    conversoes[0][0] = 1;        // Metros para Metros
    conversoes[0][1] = 3.2808;   // Metros para Pes
    conversoes[0][2] = 1.0936133; // Metros para Jardas
    conversoes[0][3] = 39.3700787; // Metros para Polegadas

    conversoes[1][0] = 1 / 3.2808; // Pes para Metros
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

    // Multiplicacao para obter a conversao desejada
    d *= conversoes[x - 1][y - 1];
    printf("%.2f %s\n", d, unidades[y - 1]);

    for (int i = 0; i < num_unidades; i++) 
    {
        free(conversoes[i]);
    }
    free(conversoes);
}

// Funcao para converter unidades de massa
void massa(float m)
{
    char *unidades[] = {"Gramas", "Quilogramas", "Libras", "Oncas"};
    int num_unidades = 4;
    float **conversoes = (float **)malloc(num_unidades * sizeof(float *));

    for (int i = 0; i < num_unidades; i++)
    {
        conversoes[i] = (float *)malloc(num_unidades * sizeof(float));
    }

    conversoes[0][0] = 1;            // Gramas para Gramas
    conversoes[0][1] = 0.001;        // Gramas para Quilogramas
    conversoes[0][2] = 0.00220462;   // Gramas para Libras
    conversoes[0][3] = 0.03527396;   // Gramas para Oncas

    conversoes[1][0] = 1000;         // Quilogramas para Gramas
    conversoes[1][1] = 1;            // Quilogramas para Quilogramas
    conversoes[1][2] = 2.20462;      // Quilogramas para Libras
    conversoes[1][3] = 35.27396;     // Quilogramas para Oncas

    conversoes[2][0] = 453.592;      // Libras para Gramas
    conversoes[2][1] = 0.453592;     // Libras para Quilogramas
    conversoes[2][2] = 1;            // Libras para Libras
    conversoes[2][3] = 16;           // Libras para Oncas

    conversoes[3][0] = 28.3495;      // Oncas para Gramas
    conversoes[3][1] = 0.0283495;    // Oncas para Quilogramas
    conversoes[3][2] = 0.0625;       // Oncas para Libras
    conversoes[3][3] = 1;            // Oncas para Oncas

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

    m *= conversoes[x - 1][y - 1];
    printf("%.2f %s\n", m, unidades[y - 1]);

    for (int i = 0; i < num_unidades; i++)
    {
        free(conversoes[i]);
    }
    free(conversoes);
}

int main()
{
    Conversao conversoes[100];
    int n = 0;

    carregarConversoes(conversoes, &n);

    while (1)
    {
        int opcao, continuar;
        float valor;
        printf("Escolha uma opcao:\n");
        printf("1. Tempo\n");
        printf("2. Temperatura\n");
        printf("3. Distancia\n");
        printf("4. Massa\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        if (opcao == 5)
        {
            break;
        }

        printf("Digite o valor a ser convertido:\n");
        scanf("%f", &valor);

        switch (opcao)
        {
            case 1:
                tempo(valor);
                strcpy(conversoes[n].tipo, "Tempo");
                break;
            case 2:
                temperatura(valor);
                strcpy(conversoes[n].tipo, "Temperatura");
                break;
            case 3:
                distancia(valor);
                strcpy(conversoes[n].tipo, "Distancia");
                break;
            case 4:
                massa(valor);
                strcpy(conversoes[n].tipo, "Massa");
                break;
            default:
                printf("Opcao invalida!\n");
                continue;
        }

        conversoes[n].valorOriginal = valor;
        printf("Voce quer fazer outra conversao? (1-Sim, 0-Nao)\n");
        scanf("%d", &continuar);
        if (!continuar)
        {
            break;
        }
    }

    salvarConversao(conversoes, n);

    return 0;
}
