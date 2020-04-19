#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    //printf("L1:");
    //Print(L1);
    //printf("L2:");
    //Print(L2);
    //printf("\n");
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    List L;
    List P1;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    P1 = L;
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        List p = (List)malloc(sizeof(struct Node));
        scanf("%d",&p->Data);
        p->Next = NULL;
        P1->Next = p;
        P1 = P1->Next;
    }
    return L;
}

void Print(List L)
{
    List L1 = L;
    if(L1->Next == NULL){
        printf("NULL\n");
        return;
    }
    while(L1->Next != NULL){
        printf("%d ",L1->Next->Data);
        L1->Next = L1->Next->Next;
    }
}

List Merge(List L1, List L2)
{
    List New;
    List P1;
    New = (List)malloc(sizeof(struct Node));
    New->Next = NULL;
    P1 = New;
    while((L1->Next != NULL)||(L2->Next != NULL)){
        if(L1->Next == NULL && L2->Next != NULL){
            P1->Next = L2->Next;
            L2->Next = NULL;
            P1 = P1->Next;
        }
        else if(L1->Next != NULL && L2->Next == NULL){
            P1->Next = L1->Next;
            L1->Next = NULL;
            P1 = P1->Next;
        }
        else{
            if(L1->Next->Data < L2->Next->Data){
                P1->Next = L1->Next;
                L1->Next = L1->Next->Next;
                P1 = P1->Next;
            }
            else if(L1->Next->Data > L2->Next->Data){
                P1->Next = L2->Next;
                L2->Next = L2->Next->Next;
                P1 = P1->Next;
            }
            else{
                P1->Next = L1->Next;
                L1->Next = L1->Next->Next;
                P1 = P1->Next;
                P1->Next = L2->Next;
                L2->Next = L2->Next->Next;
                P1 = P1->Next;
            }
        }
    }
    return New;
}