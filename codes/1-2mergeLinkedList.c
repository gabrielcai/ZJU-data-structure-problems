#include <stdio.h>
#include <stdlib.h>
//使用原序列中的节点
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

void DestroyList(List L);

List Read(){
    int N;
    List L;//定义一个节点指针，用于保存链表链表第一个节点的地址
    int i = 0,j=0;
    scanf("%d",&N);
    L = (PtrToNode)malloc(sizeof(struct Node));//定义一个节点作为头节点并赋给节点指针
    //L->Data=N;
    L->Next=NULL;//初始化头结点

    PtrToNode tmp;
    tmp=L;
    for (i = 0;i < N;i++) {
        //创建一个新节点并初始化
        PtrToNode node = (PtrToNode)malloc(sizeof(struct Node));
        scanf("%d",&j);
        node->Data=j;
        node->Next=NULL;
        tmp->Next=node;
        tmp=node;
    }

    return L;
}

void Print(List L){
    /*if (L == NULL) {
        printf("NULL");
    }else {*/
        L=L->Next;
        while (L) {
            printf("%d ",L->Data);
            L=L->Next;
        }
}
List Merge(List L1,List L2){
    int tmp=0;
    List M,N;
    List r,temp;
    M=L1->Next;
    N=L2->Next;
    r=(PtrToNode)malloc(sizeof(struct Node));
    r->Next=NULL;
    temp=r;
    while (M!=NULL&&N!=NULL) {
        if (M->Data<N->Data) {
            temp->Next=M;
            M=M->Next;
            temp=temp->Next;
        }else {
            temp->Next=N;
            N=N->Next;
            temp=temp->Next;
        }

    }
    if(M!=NULL){
        while (M) {
            temp->Next=M;
            M=M->Next;
            temp=temp->Next;
        }
    }
    if(N!=NULL){
        while (N) {
            temp->Next=N;
            N=N->Next;
            temp=temp->Next;
        }
    }
    L1->Next=NULL;
    L2->Next=NULL;
    temp->Next=NULL;
    return r;
}
int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
