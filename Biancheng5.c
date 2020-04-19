#include<stdio.h>
#include<stdlib.h>
typedef struct stack *S;
struct stack{
    int Data[1000];
    int maxsize;
    int dangqian;
};
push(S zhan, int data)
{
    zhan->Data[zhan->dangqian+1] = data;
    zhan->dangqian++;
}
int pop(S zhan)
{
    int x = zhan->Data[zhan->dangqian];
    zhan->dangqian--;
    return x;
}
ChongzhiYUAN(S zhan, int N)
{
    for(int i = N; i > 0; i--){
        push(zhan, i);
    }
}
ChongzhiBIAN(S zhan)
{
    zhan->dangqian = -1;
}
int main(void)
{
    int M, N, K;
    scanf("%d%d%d",&M, &N, &K);
    int Data[N];
    S YUAN;
    YUAN = (S)malloc(sizeof(struct stack));
    YUAN->maxsize = N;
    YUAN->dangqian = -1;
    ChongzhiYUAN(YUAN, N);
    S BIAN = (S)malloc(sizeof(struct stack));
    BIAN->maxsize = M;
    BIAN->dangqian = -1;
    //int Data[N];
    int X = 0;
    int PIVOT = 0;
    for(int p = 0; p < K; p++){
        for(int j = 0; j < N; j++){
            scanf("%d",&Data[j]);
        }
        for(int i = 0; i < N; i++){
            if(i == 0){
                if(Data[i] > M){
                    PIVOT = 1;
                }
                else{
                    for(int u = 1; u <= Data[i]; u++){
                        push(BIAN, u);
                        X = u;
                    }
                    X = X + 1; 
                    pop(BIAN);
                }
            }
            else{
                //判断Data[i]和Data[i-1]比较大小
                if(Data[i] > Data[i-1]){
                    for(int u = X; u <= Data[i]; u++){
                        push(BIAN, u);
                    }
                    if(BIAN->dangqian >= BIAN->maxsize){
                        PIVOT = 1;
                    }
                    X = Data[i]+1;
                    pop(BIAN);
                }
                else{
                    int r = pop(BIAN);
                    if(r != Data[i]){
                        PIVOT = 1;
                    }
                }
            }
        }
        if(PIVOT == 1)
            printf("NO\n");
        if(PIVOT == 0)
            printf("YES\n");
        PIVOT = 0;
        ChongzhiBIAN(BIAN);
    }
}