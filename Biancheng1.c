#include<stdio.h>
int main(void)
{
    int N;
    int MAX = 0;
    int DMAX = 0;
    int a;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&a);
        DMAX = DMAX + a;
        if(MAX < DMAX)
            MAX = DMAX;
        if(DMAX < 0)
            DMAX = 0;
    }
    printf("%d",MAX);
    return 0;
}