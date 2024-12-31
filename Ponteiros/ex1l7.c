#include <stdio.h>
#include <stdlib.h>

// num1 eh multiplo do num2 ou vice versa
// num1 = num2*x
int equivalente(int num1, int den1, int num2, int den2){
    int den3=den1*den2;

    num1=den3/den1*num1;
    num2=den3/den2*num2;
    if(num1 == num2) return 1;
    else return 0;
}

int main(){
    int t,i,j,k,n;
    scanf("%d",&t);

    int *num;
    int *den;
    for(i=0; i<t; i++){
        scanf("%d",&n);
        num= (int *) malloc(n*sizeof(int));
        den = (int *) malloc(n*sizeof(int));
        for(j=0; j<n; j++){
            int x,y; 
            char c;
            //      1 / 2
            scanf("%d%c%d", &x, &c, &y);
            num[j]=x;
            den[j]=y;
        }
        int ok=1;
        printf("Caso de teste %d\n",i+1);
        for(j=0; j<n; j++){
            for(k =j+1; k<n; k++){
                if(equivalente(num[j],den[j],num[k],den[k])){
                    ok=0;
                    printf("%d/%d equivalente a %d/%d\n",num[j],den[j],num[k],den[k]);
                }
            }
        }
        if(ok) printf("Nao ha fracoes equivalentes na sequencia\n");
        free(num);
        free(den);
    }

    return 0;
}