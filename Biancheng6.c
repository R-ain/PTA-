#include<stdio.h>
#include<stdlib.h>
typedef struct Node *Tree;
struct Node{
    char Data;
    int left;
    int right;
    int GENG;
};
Tree Read(Tree T, int N)
{
    //struct Node T[8];
    T = (Tree)malloc(sizeof(struct Node)*10);
    char a, b, c;
    char kong1, huiche, kong2;
    for(int i=0; i<N; i++){
        scanf("%c%c%c%c%c%c",&huiche, &a, &kong1, &b, &kong2, &c);
        if(b == '-' && c == '-'){
            T[i].left = -1;
            T[i].right = -1;
        }
        else if(b == '-' && c != '-'){
            T[i].left = -1;
            T[i].right = c - '0';
        }
        else if(b != '-' && c == '-'){
            T[i].right = -1;
            T[i].left = b - '0';
        }else{
            T[i].left = b - '0';
            T[i].right = c - '0';
        }
        T[i].Data = a;
        T[i].GENG = 1;
    }
    return T;
}
int FindGENG(Tree T, int N)
{
    for(int i=0; i<N; i++){
        if(T[i].left != -1){
            T[T[i].left].GENG = 0;
        }
        if(T[i].right != -1){
            T[T[i].right].GENG = 0;
        }
    }
    for(int i=0; i<N; i++){
        if(T[i].GENG == 1)
            return i;
    }
}
void Panduan(Tree T1, Tree T2, int X1, int X2, int *O)
{
    if(T1[X1].left == -1&&T1[X1].right == -1 && T2[X2].left == -1&&T2[X2].right ==-1){
        return;
    }
    else if(T1[T1[X1].left].Data == T2[T2[X2].left].Data&&T1[T1[X1].right].Data == T2[T2[X2].right].Data){
        if(T1[X1].left == -1&&T1[X1].right != -1){
            Panduan(T1, T2, T1[X1].right, T2[X2].right, O);
            return ;
        }
        else if(T1[X1].left != -1&&T1[X1].right == -1){
            Panduan(T1, T2, T1[X1].left, T2[X2].left, O);
            return ;
        }
        else if(T1[X1].left != -1&&T1[X1].right != -1){
            Panduan(T1, T2, T1[X1].left, T2[X2].left, O);
            Panduan(T1, T2, T1[X1].right, T2[X2].right, O);
            return;
        }
        else
            return ;
    }
    else if(T1[T1[X1].left].Data == T2[T2[X2].right].Data&&T1[T1[X1].right].Data == T2[T2[X2].left].Data){
        if(T1[X1].left == -1&&T1[X1].right != -1){
            Panduan(T1, T2, T1[X1].right, T2[X2].left, O);
            return;
        }
        else if(T1[X1].left != -1&&T1[X1].right == -1){
            Panduan(T1, T2, T1[X1].left, T2[X2].right, O);
            return;
        }
        else if(T1[X1].left != -1&&T1[X1].right != -1){
            Panduan(T1, T2, T1[X1].left, T2[X2].right, O);
            Panduan(T1, T2, T1[X1].right, T2[X2].left, O);
            return;
        }
        else
            return;
    }
    else{
        *O = 1;
        return;
    }
}
int main(void)
{
    int N1;
    int N2;
    scanf("%d",&N1);
    if(N1 == 0){
        printf("Yes");
        return 0;
    }
    Tree T1, T2;
    T1 = Read(T1, N1);
    scanf("%d",&N2);
    T2 = Read(T2, N2);
    int GENG1 = FindGENG(T1, N1);
    int GENG2 = FindGENG(T2, N2);
    if(N1 != N2 || T1[GENG1].Data != T2[GENG2].Data){
        printf("No");
        return 0;
    }
    int *O = (int *)malloc(sizeof(int));
    *O = 0;
    Panduan(T1, T2, GENG1, GENG2, O);
    if(*O == 1)
        printf("No");
    else
        printf("Yes");
}