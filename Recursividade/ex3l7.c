#include <stdio.h>

int achar_5(int x){
    if(x == 0) return 0;
    else{
        if(x%10 == 5){
            // 345 -> /10 ->
            // 34,0
            return 1+achar_5(x/10);
        }else if(x%10 != 5){
            return achar_5(x/10);
        }
    }
}

int main()
{
    int i, x, j, tam;
    scanf("%d", &i);
    while(i>0)
    {
        scanf("%d", &x);
        // 503245054
        int sum=achar_5(x);
        // printf("%d\n",sum);
        printf("%d\n",achar_5(x));
        i--;
    }
    return 0;
}