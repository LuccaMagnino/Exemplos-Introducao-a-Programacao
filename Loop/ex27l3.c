#include <stdio.h>
#include <math.h>

double factorial(int a) {
    int result = a;
 
    if (a == 0) {
        return 1;
    }
 
    for (int i = 1; i < a; i++){
        result *= (a-i);
    }
    return result;
}
 
int main(){
 
    int numN, i;
    double numerador, denominador;
    double cos = 0, func_numerador, func_denominador;
    double aux, numX;
 
    scanf("%lf %d", &numX, &numN);
 
    aux = numX;
 
    for(i = 1; i <= numN; i++){
        numerador = pow(-1, i-1) * (pow(numX, 2*i-1));
        denominador = factorial(2 * i - 1);
        cos += numerador / denominador;  
    }

    print("cos(%.2lf) = %.6lf\n", numX, cos);

    return 0;
}