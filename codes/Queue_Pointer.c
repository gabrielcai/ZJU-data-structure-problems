#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10 
#define Null -1

typedef int ElementType;


typedef int Tree;


typedef struct Node{
	Tree Element;
	struct Node * Next;
}NODE, *PNODE;


typedef struct QNode {
    PNODE Front, Rear; 
    int Size;
} Queue, *PQueue;

void InitQueue(PQueue);    //   Initialize queue
int  IsEmptyQueue(PQueue);    //  IsEmpty?
void EnQueue(PQueue, Tree);    //   
void PopQueue(PQueue, Tree * );    //   
void ClearQueue(PQueue);    //    ??????


void InitQueue(PQueue PQ){
	PQ->Front = PQ->Rear = (PNODE) malloc(sizeof (NODE));
	if(PQ->Front==NULL){
		printf("Queue initialization failed.\n");
	}
	
}

int IsEmptyQueue(PQueue PQ){
	 if (PQ->Front == PQ->Rear) {
        return 1;
    }
    else {
        return 0;
    }
}

void EnQueue(PQueue PQ, Tree T){
	PNODE tmp = (PNODE) malloc(sizeof (NODE));
	tmp->Element = T;
	tmp->Next = NULL;
	PQ->Rear->Next = tmp;
	PQ->Rear = tmp;
	PQ->Size ++;
}

void PopQueue(PQueue PQ, Tree * PT ){
	if (IsEmptyQueue(PQ)) exit(-1);
	PNODE tmp = PQ->Front->Next;
	*PT = tmp->Element;
	PQ->Front->Next = tmp->Next;
	if (PQ -> Rear==tmp)
        PQ->Rear = PQ->Front;
    free(tmp);  
    PQ->Size--;
}

void TraverseQueue(PQueue queue) {
    if (!IsEmptyQueue(queue)) {
    	 PNODE P = queue->Front->Next;    
    while (P != NULL) {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
        
    }        
   
}

void ClearQueue(PQueue queue) {
    PNODE P = queue->Front->Next;    // 
    PNODE Q = NULL;        //   
    queue->Rear = queue->Front;        //  
    queue->Front->Next = NULL;
    while (P != NULL) {
        Q = P;
        P = P->Next;
        free(Q);
    }
}

