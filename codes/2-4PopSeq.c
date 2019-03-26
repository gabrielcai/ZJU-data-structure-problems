#include <stdio.h>
#include <stdlib.h>
#define  MAXSIZE 100000
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

//Function headers;
int IsEmpty ( Stack S);
Stack CreatStack( void);
void MakeEmpty(Stack S);
ElementType Pop( Stack S);
void Push( ElementType e, Stack S, int MaxSize);
char * isValid(int* PopSeq,int  N,int MaxSize);
void Print (Stack S);
// define Stack structure
struct Node{
	ElementType Element;
	int Size;
	PtrToNode Next;
};

int IsEmpty( Stack S){
	return NULL == S -> Next ;
}
Stack CreatStack( void ){
	Stack S;
	S = (Stack) malloc(sizeof(struct Node ) );
	S -> Size = 0;
	S -> Next = NULL;
	return S;
}

void MakeEmpty(Stack S){
	while ( ! IsEmpty( S ))
		Pop( S );
}

ElementType Pop( Stack S){
	PtrToNode TopCell;
	ElementType e; 
	if( IsEmpty (S)) {
		//printf("Stack is empty./n");
		;
	}
	else {
		TopCell	  = S -> Next;
		e = TopCell -> Element;
		S -> Next = S -> Next -> Next;
		free (TopCell);	
		S -> Size --;
		return e;
	}
}

void Print (Stack S){
	PtrToNode TmpCell = S->Next;
	while(TmpCell != NULL){
		printf("%d ", TmpCell->Element);
		TmpCell = TmpCell->Next;
	}
	printf("\n");
}
ElementType Top( Stack S){
	if( IsEmpty (S)) {
	//printf("Stack is empty./n");
		return 1;
	}
	else return( S->Next->Element); 
}

void Push( ElementType e, Stack S, int MaxSize){
	    if( S -> Size == MaxSize)  
			;
	    else {
	    	PtrToNode TmpCell =(PtrToNode) malloc (sizeof (struct Node ) );
			TmpCell -> Element  = e;
			TmpCell -> Next     = S -> Next;
			S 		-> Next 	= TmpCell;
			S		-> Size ++;
		}
	}

int main(){
//	FILE *myFile;
//    myFile = fopen("2.4.txt", "r");
//    int MaxSize, N, K;
//	fscanf(myFile, "%d", &MaxSize);
//	fscanf(myFile, "%d", &N);
//	fscanf(myFile, "%d", &K);

    int MaxSize, N, K;
	scanf("%d", &MaxSize);
	scanf( "%d", &N);
	scanf("%d", &K);
	int i,j;
	int PopSeq[N];
	
	for( i = 0; i < K; i++){
		for ( j = 0; j < N; j++ ){ //read entry
		scanf("%d", &PopSeq[j]); 
		}
//		for ( j = 0; j < N; j++ ){
//		printf("%d ", PopSeq[j]); 
//		}
//		printf("\n\n"); 
		printf("%s\n",isValid(PopSeq, N, MaxSize)); 
	} 
	return 0;
}

char * isValid(int PopSeq[],int  N,int MaxSize){
	Stack EntrySeq =CreatStack(); // contain N N-1 ... 1
	int j;
	for ( j = N; j>0; j--){
				Push(j,EntrySeq,N) ;
	} 
	Stack S =CreatStack(); // to push and pop
	Push(Pop(EntrySeq), S, MaxSize);
	//Print(S);
	for ( j = 0; j<N; j++){
		while( !IsEmpty(EntrySeq) && PopSeq[j] != Top(S))
			{
				Push(Pop(EntrySeq), S, MaxSize);
				//Print(S);
			}		
			if (PopSeq[j] == Top(S)) {
			Pop(S);
			//printf("%d%d ", PopSeq[j],Pop(S)); 
			continue;
			}
		else return ("NO");
		
	}
	return ("YES");
	
}

