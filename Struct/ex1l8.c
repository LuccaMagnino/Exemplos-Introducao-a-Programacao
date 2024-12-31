#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerador;
    int denominador;
} Fracao;

int mdc(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int saoEquivalentes(Fracao f1, Fracao f2) 
{
    int mdc_numerador = mdc(f1.numerador, f2.numerador);
    int mdc_denominador = mdc(f1.denominador, f2.denominador);

    int num1 = f1.numerador / mdc_numerador;
    int den1 = f1.denominador / mdc_denominador;
    int num2 = f2.numerador / mdc_numerador;
    int den2 = f2.denominador / mdc_denominador;
    
    return (num1 == num2 && den1 == den2);
}

int main() {
    int n; 
    scanf("%d", &n);
    
    for (int caso = 1; caso <= n; caso++) {
        int m; // tamanho da sequência de frações
        scanf("%d", &m);
        
        Fracao *fractions = (Fracao *) malloc(m * sizeof(Fracao));
        
        // Leitura das frações
        for (int i = 0; i < m; i++) {
            scanf("%d/%d", &fractions[i].numerador, &fractions[i].denominador);
        }
        
        printf("Caso de teste %d\n", caso);
        
        int encontrou_equivalentes = 0;
        
        // Comparação de todas as frações com todas as outras
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (saoEquivalentes(fractions[i], fractions[j])) {
                    printf("%d/%d equivalente a %d/%d\n", fractions[i].numerador, fractions[i].denominador,
                           fractions[j].numerador, fractions[j].denominador);
                    encontrou_equivalentes = 1;
                }
            }
        }
        
        if (!encontrou_equivalentes) {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
        
        free(fractions);
        printf("\n");
    }
    
    return 0;
}
