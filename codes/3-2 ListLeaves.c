#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
#define Null -1

typedef int ElementType;
typedef enum {True False} bool;
typedef int Tree;
typedef struct Node * PtrToNode;

typedef struct Node{
	Tree Element;
	PtrToNode Next;
}NODE, *PNODE;


typedef struct QNode {
    PNODE Front, Rear; 
    int Size;
} Queue, *PQueue;

struct TNode{
	ElementType Element;
	Tree Lc;
	Tree Rc;
}MyTree[ MaxSize ];

void InitQueue(PQueue);    //   Initialize queue
int  IsEmptyQueue(PQueue);    // 
void EnQueue(PQueue, Tree);    //   
void PopQueue(PQueue, Tree * );   
void ClearQueue(PQueue);    
void BFS(struct TNode T[], Tree R);
void PopQueue(PQueue PQ, Tree * PT );
Tree BuildTree( struct TNode  T[],FILE * myFile);
void Visit(struct TNode T[], Tree R);
void BFS(struct TNode T[], Tree R);

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
    if (IsEmptyQueue(queue)) {
        exit(-1);
    }        
    PNODE P = queue->Front->Next;    
    while (P != NULL) {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
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



int flag = 0;

int main() {
    FILE *myFile;
    myFile = fopen("3.2.txt", "r");
    Tree R;
    R = BuildTree(MyTree,myFile);  
    //R = BuildTree(MyTree);  
	//InOrderPrintTree(MyTree,R)  ;
	//printf("%d",R);
	
	BFS(MyTree,  R);
    return 0;
}




Tree BuildTree( struct TNode  T[],FILE * myFile){
	int N;
	int i;
	fscanf(myFile,"%d", &N);
	int isChild[N]; // flag that n-th node is child of some other nodes
	if(N){
		for ( i = 0; i < N; i++) isChild[i] = 0; 	
		for ( i = 0; i < N; i++){
			char l,r;
			fscanf(myFile,"\n%c %c", &l, &r);
			T[i].Element = i;
			if( l != '-'){
				T[i].Lc = l - '0';
				isChild[T[i].Lc] = 1;
			}
			else T[i].Lc = Null;
			if( r != '-'){
				T[i].Rc = r - '0';
				isChild[T[i].Rc] = 1;
			}
			else T[i].Rc = Null; 			     
		}
	}
	else return -1;
	Tree Root;
	for ( i = 0; i < N; i++){
		if (!isChild[i]) {	
			Root = i;
		}
	}
	return Root;
	}
//Tree BuildTree( struct TNode  T[]){
//	int N;
//	int i;
//	scanf("%d", &N);
//	int isChild[N]; // flag that n-th node is child of some other nodes
//	if(N){
//		for ( i = 0; i < N; i++) isChild[i] = 0; 	
//		for ( i = 0; i < N; i++){
//			char l,r;
//			scanf("\n%c %c", &l, &r);
//			if( l != '-'){
//				T[i].Lc = l - '0';
//				isChild[T[i].Lc] = 1;
//			}
//			else T[i].Lc = Null;
//			if( r != '-'){
//				T[i].Rc = r - '0';
//				isChild[T[i].Rc] = 1;
//			}
//			else T[i].Rc = Null; 			     
//		}
//	}
//	else return -1;
//	Tree Root;
//	for ( i = 0; i < N; i++){
//		if (!isChild[i]) {	
//			break;
//		}
//	}
//	Root = i;
//	return Root;
//	}



void Visit(struct TNode T[], Tree R){
	if (T[R].Lc==Null && T[R].Rc==Null) {
		if(0 == flag) {
			printf("%d", T[R].Element );
			flag = 1;
		}
	 	else printf(" %d", T[R].Element );
	 }
	//printf("%d", T[R].Element );
}

void BFS(struct TNode T[], Tree R){
	Queue queue;
	InitQueue(&queue);  
	EnQueue(&queue,R);
	Tree tmp;
	while(!IsEmptyQueue(&queue) ) {
		TraverseQueue(&queue);	
		PopQueue(&queue, &tmp);
	
		//Visit(T,tmp);
		if(T[tmp].Lc!=Null) 
			EnQueue(&queue,T[tmp].Lc);
		if(T[tmp].Rc!=Null) 
			EnQueue(&queue,T[tmp].Rc);
	}
	ClearQueue(&queue);
}


