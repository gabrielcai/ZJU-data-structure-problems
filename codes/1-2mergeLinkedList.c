#include <stdio.h>
#include <stdlib.h>
//ʹ��ԭ�����еĽڵ�
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

void DestroyList(List L);

List Read(){
    int N;
    List L;//����һ���ڵ�ָ�룬���ڱ������������һ���ڵ�ĵ�ַ
    int i = 0,j=0;
    scanf("%d",&N);
    L = (PtrToNode)malloc(sizeof(struct Node));//����һ���ڵ���Ϊͷ�ڵ㲢�����ڵ�ָ��
    //L->Data=N;
    L->Next=NULL;//��ʼ��ͷ���

    PtrToNode tmp;
    tmp=L;
    for (i = 0;i < N;i++) {
        //����һ���½ڵ㲢��ʼ��
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
