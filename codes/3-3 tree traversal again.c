#include <stdio.h>
#include <string.h>
#define MaxSize 30
#define Null -1
#define ERROR -1

typedef int ET;
typedef int Tree;
typedef int Position;

struct TreeNode{
	ET Element;
	Tree Lc;
	Tree Rc;
} MyTree[MaxSize];

typedef struct StackNode * PtrToSnode;
struct StackNode{
	ET* Array;
	Position Top;
	int Capacity;
};
typedef PtrToSnode Stack;
int flag;
Stack CreatStack(int Capacity){
	Stack S = (Stack) malloc (sizeof(struct StackNode));
	S->Array = (ET* ) malloc(sizeof( ET)*Capacity);
	S->Top = -1;
	S->Capacity = Capacity;	
	return S;
}

int IsFull(Stack S){
	return( S->Top == S->Capacity-1);
}

int Push(Stack S, ET x){
	if(IsFull(S)) return -1;
	else {
		S->Array[++(S->Top)] = x;
		return 1;
	}	
} 

ET Pop(Stack S){
	if(-1 == S->Top) return ERROR;
	else return S->Array[(S->Top)--];
}

ET Peek(Stack S){
	if(-1 == S->Top) return ERROR;
	else return S->Array[S->Top];
}

void GetPreIn(int ** PtrToPre,int ** PtrToIn,int * N){
        freopen("3.3.txt", "r",stdin);
	scanf("%d ", N);
	int Size = *N;
	*PtrToPre = (int *) malloc(sizeof(int)*Size);
	*PtrToIn  = (int *) malloc(sizeof(int)*Size);
	int poI = -1,ioI = -1;
	Stack S = CreatStack(Size);
	int x;
	int i;
	for (i=0; i<2*Size; i ++){
		char Operation[10];
		scanf("%s",Operation);
		 if(strcmp(Operation, "Push") == 0){
			scanf(" %d\n",&x);
			//printf("Push %d",x);
			Push(S,x-1);
			(*PtrToPre)[++poI] =x-1; 
		}
		else  {
			(*PtrToIn)[++ioI]=Pop(S);
			//printf("Pop %d",inorder[ioI]);
		}
	}
}

Tree Reconstruct( 
				int * Pre, int Pa, int Pb,
				int * In, int Ia, int Ib){
	int i;
	Tree Root = Null;
	if (Pa > Pb) return Root;
	else { 
		Root = Pre[Pa];
		int j=0; while(In[Ia+j]!=Root) j++; //find the index in InOrder
		MyTree[Root].Lc = Reconstruct(Pre,Pa+1,Pa+j,In,Ia,Ia+j-1);
		MyTree[Root].Rc = Reconstruct(Pre,Pa+j+1,Pb,In,Ia+j+1,Ib);
	}
	return Root;
	
	
}
void PostTraverse(int T){ 
	if(T != Null){
		PostTraverse(MyTree[T].Lc);
		PostTraverse(MyTree[T].Rc);
		if (flag) {
			printf("%d",MyTree[T].Element);
			flag = 0;
		}
		else {
			printf(" %d",MyTree[T].Element);
		}
	}
}

int main(){
	int N;
	int *Pre,*In,*Post;
	GetPreIn(&Pre, &In, &N);
	int i;
//	printf("PreOrder: ");
//	for (i=0; i<N; i ++){
//		printf("%d ",Pre[i]);
//	}
//	printf("\n");
//	printf("InOrder:  ");
//	for (i=0; i<N; i ++){
//		printf("%d ",In[i]);
//	}
//	printf("\n");
	for ( i = 0; i < N; i++){//³õÊ¼»¯Ê÷ 
			MyTree[i].Element = i+1;
			MyTree[i].Lc 	= Null;
			MyTree[i].Rc 	= Null;}
	int Root = Reconstruct(Pre,0, N-1, In,0,N-1);
	flag = 1;
	PostTraverse(Root);
	
//	Stack S = CreatStack(10);
//	Push(S,1);
//	Push(S,2);
//	printf("%d ",Pop(S));
//	printf("%d ",Pop(S));
	return 0;
}
