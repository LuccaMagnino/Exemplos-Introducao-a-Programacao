#include <stdio.h>

void tempo(float te) //Funcao para a conversao de unidades de tempo
 {
      int I1; // Identificador para padronizacao
    printf("Qual a sua unidade de tempo?\n Digite 1 para Segundos\n Digite 2 para Minutos\n Digite 3 para Hora\n");
    scanf("%d", &I1);

    switch (I1) //Padronizacao para segundos
    {

        case 1:
           te = te;
            break;

        case 2:
            te = te*60;
            break;

        case 3:
            te = te*3600;
            break;

        default:
            printf("Voce digitou um numero invalido\n");
            break;
      }
    int I2; // Identificador para conversao
    printf("Voce quer converter para qual unidade?\n Digite 1 para Segundos\n Digite 2 para Minutos\n Digite 3 para Horas\n");
    scanf("%d", &I2);

    switch (I2) //Conversao de segundos para outras unidades
    {
        case 1:
            te = te;
            printf("%d Segundos\n",(int)te);
            break;

        case 2:
            te = te/60;
            float decimal=(te-((int)te))*60;
             printf("%d Minutos %d Segundos\n", (int)te,(int)decimal);
            break;

        case 3:
            te = te/3600;
            float decimal1=(te-((int)te))*60;
            float decimal2 =(decimal1-((int)decimal1))*60;
            printf("%d Horas %d Minutos %d Segundos\n", (int)te,(int)decimal1,(int)decimal2);
            break;

        default:
            printf("Voce digitou um numero invalido\n");
            break;
    }
      return; //Retorna o valor convertido 
 }

void temperatura(float t) //Funcao para a conversao de unidades de temperatura
{
    int I1; // Identificador de padronizacao
    printf("Qual a sua unidade de temperatura?\n Digite 1 para Celsius\n Digite 2 para Fahrenheit\n Digite 3 para Kelvin\n");
    scanf("%d", &I1);

    switch (I1) //Padronizacao para Kelvin
    {

        case 1:
           t = t + 273.15;
            break;

        case 2:
            t = ((t - 32) / 1.8) + 273.15;
            break;

        case 3:
            t = t;
            break;

        default:
            printf("Voce digitou um numero invalido\n");
            break;
    }
    int I2; // Identificador de conversão
    printf("Voce quer converter para qual unidade?\n Digite 1 para Celsius\n Digite 2 para Fahrenheit\n Digite 3 para Kelvin\n");
    scanf("%d", &I2);

    switch (I2) //Conversao de Kelvin para outras unidades
    {
        case 1:
            t = t - 273;
            printf("%.2fC\n", t);
            break;

        case 2:
            t = (t * 1.8) - 459.67;
            printf("%.2fF\n", t);
            break;

        case 3:
            t = t;
            printf("%.2fK\n", t);
            break;

        default:
            printf("Voce digitou um numero invalido\n");
            break;
    }
    return;
}

  void distancia(float d)//Funcao para a conversao de unidades de distancia
 {
      int I1; // Identificador para padronizacao
    printf("Qual a sua unidade de distancia?\n Digite 1 para Metros(m)\n Digite 2 para Pes(ft)\n Digite 3 para Jardas(yd)\n Digite 4 para Polegadas(in)\n");
    scanf("%d", &I1);

    switch (I1) //Padronizacao para metros
    {

        case 1:
           d = d;
            break;

        case 2:
            d = d/3.2808;
            break;

        case 3:
            d = d/1.0936133;
            break;

        case 4:
            d= d/39.3700787;
            break;
            
        default:
            printf("Voce digitou um numero invalido\n");
            break;
      }
    int I2; // Identificador para conversao
    printf("Voce quer converter para qual unidade?\n Digite 1 para Metros(m)\n Digite 2 para Pes(ft)\n Digite 3 para Jardas(yd)\n Digite 4 para Polegadas(in)\n");
    scanf("%d", &I2);

    switch (I2) //Conversao de metros para outras unidades
    {
        case 1:
            d = d;
            printf("%.3f Metros\n",d);
            break;

        case 2:
            d = d*3.2808;
             printf("%.3f Pes\n",d);
            break;

        case 3:
            d = d*1.0936133;
            printf("%.3f Jardas\n",d);
            break;

        case 4:
            d = d*39.3700787;
            printf("%.3f Polegadas\n",d);
            break;

        default:
            printf("Voce digitou um numero invalido\n");
            break;
    }
      return;
 }

void peso (float p)//Funcao para a conversao de unidades de massa
{
    int I1; // Identificador de padronizacao
    printf("Qual a sua unidade de massa?\n Digite 1 para Quilograma\n Digite 2 para Libra/Pounds\n Digite 3 para Onca\n");
    scanf("%d", &I1);

    switch (I1)//Padroniza para Kg
    {

        case 1:
           p = p;
            break;

        case 2:
            p = p * 0.453592;
            break;

        case 3:
            p = p * 0.0283495;
            break;

        default:
            printf("Voce digitou um numero invalido\n");
            break;
    }
    int I2; // Identificador
    printf("Voce quer converter para qual unidade?\n Digite 1 para Quilograma\n Digite 2 para Libra/Pounds\n Digite 3 para Onca\n");
    scanf("%d", &I2);

    switch (I2)//Converte de Kg para outras unidades
    {
        case 1:
            p = p;
            printf("%.4f Kg\n", p);
            break;

        case 2:
            p = p * 2.20462 ;
            printf("%.4f Lb\n", p);
            break;

        case 3:
            p = p * 35.274;
            printf("%.4f Oz\n", p);
            break;

        default:
            printf("Voce digitou um numero invalido\n");
            break;
    }
    return;
}

int main()//Funcao principal, onde ira ser chamada cada uma das outras funcoes para realizar as conversoes

{
    int l = 1; // realiza o loop
    float X;   // valor colocado pelo usuario
    int I1;    // Identificador
    while (l == 1)
    {
        printf("Qual medida voce deseja converter?\n Digite 1 para temperatura\n Digite 2 para distancia\n Digite 3 para peso\n Digite 4 para tempo\n");
        scanf("%d", &I1);

        printf("Qual o valor a ser utilizado?\n"); //valor definido pelo usuario para ser convertido
        scanf("%f", &X);

        switch (I1)
        {
            case 1: //funcao temperatura
                temperatura(X);
                break;

            case 2: //funcao distancia
                distancia(X);
                break;

            case 3: //funcao peso para conveter massa
                peso(X);
                break;

            case 4: //funcao tempo
                tempo(X);
                break;
            
            default:
                printf("Voce digitou um numero invalido\n");
                break;

                
        }
        printf("Voce deseja converter mais uma unidade?\n Digite 0 para nao\n Digite 1 para sim\n");
        scanf("%d", &l);//O usuario ira definir o valor de l, sendo diferente de 1 ira parar o loop, caso seja igual a 1, ira repetir o processo para uma nova conversao

    }
    return 0;
}
