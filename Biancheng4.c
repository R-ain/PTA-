#include<stdio.h>
#include<stdlib.h>
typedef struct NodeData *PtrtoData;
typedef struct Nodelist *List;
struct NodeData{
    int Address;
    int data;
    int Next;
};
struct Nodelist{
    int Address;
    int NextAddress;
    int Data;
    List Next;
};
//Read(int *A, int *N, int *B);
/*ArraySort(struct NodeData *Shuzu);
LinklistSort(struct NodeData *Shuzu);
Print(struct Nodelist *List);
void Swap(struct NodeData *node1, struct NodeData *node2);*/

Read(struct NodeData* Data, int N)
{
    for(int i=0; i<N; i++){
        scanf("%d%d%d", &Data[i].Address, &Data[i].data, &Data[i].Next);
    }
}
Swap(struct NodeData *node1, struct NodeData *node2)
{
    int a = node1->Address;
    int b = node1->data;
    int c = node1->Next;
    node1->Address = node2->Address;
    node1->data = node2->data;
    node1->Next = node2->Next;
    node2->Address = a;
    node2->data = b;
    node2->Next = c;
}
ArraySort(struct NodeData *Data, int N, int FAD)
{
    for(int i=0; i<N; i++){
        if(Data[i].Address == FAD){
            Swap(&Data[0], &Data[i]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(Data[j].Address == Data[i].Next){
                Swap(&Data[i+1], &Data[j]);
            }
        }
    }
}
List zhuanhuan(struct NodeData *Data, int N)
{
    List L = (List)malloc(sizeof(struct Nodelist));
    L->Next = NULL;
    List P = L; 
    for(int i=0; i<N; i++){
        List ptr = (List)malloc(sizeof(struct Nodelist));
        ptr->Next = NULL;
        ptr->Address = Data[i].Address;
        ptr->Data = Data[i].data;
        ptr->NextAddress = Data[i].Next;
        P->Next = ptr;
        P = ptr;
    }
    return L;
}
List Fanzhuan(List L, int PIV, int N)
{
    List NEW = (List)malloc(sizeof(struct Nodelist));
    NEW->Next = NULL;
    List PY = L->Next;
    List p = NEW;
    int X = 0;
    while(X + PIV <= N){
        List Xnew = (List)malloc(sizeof(struct Nodelist));
        Xnew->Next = NULL;
        for(int i = X; i < X + PIV; i++){
            List ptr = (List)malloc(sizeof(struct Nodelist));
            ptr->Address = PY->Address;
            ptr->Data = PY->Data;
            ptr->NextAddress = PY->NextAddress;
            ptr->Next = Xnew->Next;
            Xnew->Next = ptr;
            PY = PY->Next;
        }
        X = X + PIV;
        while(p->Next != NULL){
            p = p->Next;
        }
        p->Next = Xnew->Next;
        Xnew = NULL;
    }
    if(X < N){
        while(p->Next != NULL){
            p = p->Next;
        }
        p->Next = PY;
    }
    return NEW;
}
int main(void)
{
    int FADDRESS;
    int N;
    int BIAN;
    scanf("%d%d%d", &FADDRESS, &N, &BIAN);
    struct NodeData* Data = (struct NodeData*)malloc(sizeof(struct NodeData)*N);
    Read(&Data[0], N);
    ArraySort(&Data[0], N, FADDRESS);
    List L = zhuanhuan(&Data[0], N);
    List P = L->Next;
    N = 1;
    while(P->NextAddress != -1){
        N++;
        P = P->Next;
    }
    P->Next = NULL;
    L = Fanzhuan(L, BIAN, N);
    P = L->Next;
    while(P->Next != NULL){
        P->NextAddress = P->Next->Address;
        P = P->Next;
    }
    P = L->Next;
    printf("\n");
    while(P->Next != NULL){
        printf("%05d %d %05d\n", P->Address, P->Data, P->NextAddress);
        P = P->Next;
    }
    printf("%05d %d -1", P->Address, P->Data, P->NextAddress);
    return 0;
}