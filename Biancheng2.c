#include<stdio.h>
int main(void)
{
    int N;
    int DMAX = 0;
    int MAX = 0;
    int F, E, DF, DE;
    scanf("%d",&N);
    int suzu[N];
    for(int i=0; i<N; i++){
        scanf("%d",&suzu[i]);
    }
    E = 0;
    F = 0;
    DF = 0;
    DE = 0;
    int pivot = 0;
    for(int i=0; i<N; i++){
        DMAX = DMAX + suzu[i];
        if(DMAX < 0){
            DMAX = 0;
            DF = i + 1;
            DE = i + 1;
        }
        else if(MAX == 0 && DMAX == 0){
            if(pivot == 0){
                F = i;
                E = i;
                pivot = 1;   
            }
            DE = i + 1;
        }
        else if(DMAX >= 0 && DMAX <= MAX){
            DE = i + 1;
        }
        
        if (DMAX > MAX){
            MAX = DMAX;
            E = i;
            F = DF;
        }
    }
    if(E == 0 && F == 0 && pivot != 1){
        F = 0;
        E = N-1;
    }
    printf("%d %d %d",MAX, suzu[F], suzu[E]);
    return 0;
}