#include<stdio.h>
#include<stdlib.h>
typedef struct Node *DXS;
struct Node{
    int xishu;
    int zhishu;
    struct Node *Next;
};

DXS Read();
void Print(DXS List);
void Add(DXS List, DXS node);
DXS Xiangjia(DXS List1, DXS List2);
DXS Xiangcheng(DXS List1, DXS List2);
DXS DXiangjia(DXS node1, DXS node2);
DXS DXiangcheng(DXS node1, DXS node2);

DXS Read()
{
    DXS Li;
    Li = (DXS)malloc(sizeof(struct Node));
    Li->Next = NULL;
    DXS p;
    p = Li;
    int N;
    scanf("%d",&N);
    if(N == 0){
        DXS L = (DXS)malloc(sizeof(struct Node));
        L->Next = NULL;
        L->xishu = 0;
        L->zhishu = 0;
        Li->Next = L;
    }
    else{
        for(int i=0; i<N; i++){
            DXS L = (DXS)malloc(sizeof(struct Node));
            scanf("%d%d", &L->xishu, &L->zhishu);
            L->Next = NULL;
            p->Next = L;
            p = p->Next;
        }
    }
    return Li;
}
DXS Dxiangjia(DXS node1, DXS node2)
{
    DXS New;
    New = (DXS)malloc(sizeof(struct Node));
    New->Next = NULL;
    New->zhishu = node1->zhishu;
    New->xishu = node1->xishu + node2->xishu;
    return New;
}
DXS DXiangcheng(DXS node1, DXS node2)
{
    DXS New;
    New = (DXS)malloc(sizeof(struct Node));
    New->Next = NULL;
    New->xishu = node1->xishu * node2->xishu;
    New->zhishu = node1->zhishu + node2->zhishu;
    /*free(node1);
    free(node2);*/
    return New;
}
DXS Xiangjia(DXS List1, DXS List2)
{
    DXS p1 = List1;
    DXS p2 = List2;
    DXS New = (DXS)malloc(sizeof(struct Node));
    New->Next = NULL;
    DXS Pt = New;
    while(p1->Next != NULL || p2->Next != NULL){
        DXS P = (DXS)malloc(sizeof(struct Node));
        P->Next = NULL;
        if(p1->Next == NULL && p2->Next != NULL){
            P->xishu = p2->Next->xishu;
            P->zhishu = p2->Next->zhishu;
            Pt->Next = P;
            Pt = Pt->Next;
            p2->Next = p2->Next->Next;
        }
        else if(p1->Next != NULL && p2->Next == NULL){
            P->xishu = p1->Next->xishu;
            P->zhishu = p1->Next->zhishu;
            Pt->Next = P;
            Pt = Pt->Next;
            p1->Next = p1->Next->Next;
        }
        else if (p1->Next->zhishu == p2->Next->zhishu){
            P->xishu = p1->Next->xishu + p2->Next->xishu;
            P->zhishu = p1->Next->zhishu;
            Pt->Next = P;
            Pt = Pt->Next;
            p1->Next = p1->Next->Next;
            p2->Next = p2->Next->Next;  
        }
        else if(p1->Next->zhishu > p2->Next->zhishu){
            P->xishu = p1->Next->xishu;
            P->zhishu = p1->Next->zhishu;
            Pt->Next = P;
            Pt = Pt->Next;
            p1->Next = p1->Next->Next; 
        }
        else{
            P->xishu = p2->Next->xishu;
            P->zhishu = p2->Next->zhishu;
            Pt->Next = P;
            Pt = Pt->Next;
            p2->Next = p2->Next->Next;
        }
    }
    return New;
}
void Print(DXS List)
{
    DXS P = List->Next;
    DXS Ptr = List;
    if(P->Next == NULL && P->xishu == 0){
        printf("0 0");
        return;
    }
    else{
        while(P->Next != NULL){
            if(P->xishu == 0){
                P = P->Next;
                Ptr->Next = P;
            }
            else{
                Ptr = P;
                P = P->Next;
            }
        }
    }
    if(P->xishu == 0){
        Ptr->Next = NULL;
    }
    if(List->Next == NULL){
        printf("0 0");
        return;
    }
    P = List->Next;
    if(P->Next == NULL){
        printf("%d %d",P->xishu, P->zhishu);
        return;
    }
    else {
        while(P->Next != NULL){
            printf("%d %d ", P->xishu, P->zhishu);
            P = P->Next;
        }
        printf("%d %d", P->xishu, P->zhishu);
    }
}

DXS Xiangcheng(DXS List1, DXS List2)//不用担心空链表，在main中处理
{
    DXS p1 = List1->Next;
    DXS p2 = List2->Next;
    DXS a, b;
    DXS Result;
    Result = (DXS)malloc(sizeof(struct Node));
    Result->Next = NULL;
    a = Result;
    while(p2 != NULL){
        DXS P = DXiangcheng(p1, p2);
        a->Next = P;
        a = a->Next;
        p2 = p2->Next;
    }
    p2 = List2->Next;
    //a = p1->Next;
    //b = p2;
    p1 = List1->Next->Next;
    while(p1 != NULL){
        while(p2 != NULL){
            DXS P = DXiangcheng(p1, p2);
            Add(Result, P);
            p2 = p2->Next;
        }
        p1 = p1->Next;
        p2 = List2->Next;
    }
    return Result;
}
void Add(DXS List, DXS Node)
{
    DXS P = List->Next;
    DXS a;
    while(Node->zhishu < P->Next->zhishu){
        P = P->Next;
        if(P->Next == NULL){
            if(Node->zhishu < P->zhishu){
                DXS node = (DXS)malloc(sizeof(struct Node));
                node->xishu = Node->xishu;
                node->zhishu = Node->zhishu;
                node->Next = NULL;
                P->Next = node;
                return;
            }
            else{
                P->xishu = P->xishu + Node->xishu;
                return;
            }
        }
    }
    if(Node->zhishu == P->zhishu){
        P->xishu = P->xishu + Node->xishu;
        return;
    }
    else if(Node->zhishu == P->Next->zhishu){
        P->Next->xishu = P->Next->xishu + Node->xishu;
        return;
    }
    else if(Node->zhishu > P->zhishu){
        DXS node = (DXS)malloc(sizeof(struct Node));
        node->xishu = Node->xishu;
        node->zhishu = Node->zhishu;
        node->Next = NULL;
        List->Next = node;
        node->Next = P;
    }
    else {
        DXS node = (DXS)malloc(sizeof(struct Node));
        node->xishu = Node->xishu;
        node->zhishu = Node->zhishu;
        node->Next = NULL;
        a = P->Next;
        P->Next = node;
        node->Next = a; 
        return; 
    }
}

int main (void)
{
    DXS L1 = Read();
    DXS L2 = Read();
    DXS CHENG = Xiangcheng(L1, L2);
    DXS JIA = Xiangjia(L1, L2);
    Print(CHENG);
    printf("\n");
    Print(JIA);
}