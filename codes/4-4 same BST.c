//04-��4 �Ƿ�ͬһ�ö��������� ��25 �֣�
//����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������
//
//�����ʽ:
//�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L����Ҫ�������С�
//
//����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����
//
//�����ʽ:
//��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����
//
//��������:
//4 2
//3 1 4 2
//3 4 1 2
//3 2 4 1
//2 1
//2 1
//1 2
//0
//�������:
//Yes
//No
//No
//��л�ൺ��ѧ��ǿ��ʦ����������ݣ�
//
//����: ��Խ
//��λ: �㽭��ѧ
//ʱ������: 400 ms
//�ڴ�����: 64 MB


#include <stdio.h>
#include <stdlib.h>
typedef int ET;
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode{
	ET Data;
	int IsVisited;
	BinTree Left;
	BinTree Right;
};

BinTree Insert( BinTree BST, ET X ){
	if(! BST) {
		BST = (BinTree) malloc (sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
		BST->IsVisited = 0;
	} else{
		if(X >= BST->Data) BST->Right = Insert( BST->Right, X );
		else BST->Left = Insert( BST->Left, X );
	}
	return BST;
}

BinTree BuildTree(int Size){
	BinTree T = NULL;
	int i;
	int X;
	for(i=0; i<Size;i++){
		scanf("%d",&X);
		T = Insert(T, X);
	}
	return T;
}  

void DestroyTree(BinTree T){
	if(T){
		DestroyTree(T->Left);
		DestroyTree(T->Right);
		free(T);
	}
}
void PreTraversal(BinTree T){
	if(T){
		printf("%d ",T->Data);
		PreTraversal(T->Left);
		PreTraversal(T->Right);
	}
}

void InTraversal(BinTree T){
	if(T){	
		InTraversal(T->Left);
		printf("%d ",T->Data);
		InTraversal(T->Right);
	}
}

void SetNoVisited(BinTree T){
	if(T){	
		T->IsVisited = 0;
		SetNoVisited(T->Left);
		SetNoVisited(T->Right);
	}
}

int CheckNext(BinTree T, ET X){
	if(!T) return 0;
	if(T->Data == X && !T->IsVisited){
		T->IsVisited = 1;
		return 1;		
	} else if(! T->IsVisited) return 0;
	  else if(X< T->Data) return CheckNext(T->Left,X);
	  else if(X> T->Data) return CheckNext(T->Right,X);
}

void Check(BinTree T,int N){
	int i;
	ET X;
	int isChecked=1;
	for(i=0; i<N;i++){
		scanf("%d",&X);
		isChecked = isChecked * CheckNext(T, X) ;
	}
	if(!isChecked) printf("No\n");
	else printf("Yes\n");
	SetNoVisited(T);
}


int main(){
	BinTree T ;
	//freopen("4.4.txt", "r",stdin);
	int N,M;
	scanf("%d",&N);
	while(N){
		scanf("%d\n",&M);
	    T = BuildTree(N);
	//	printf("PreOrder : "),
	//	PreTraversal(T);
	//	printf("\n");
	//	printf("InOrder  : "),
	//	InTraversal(T);
	//	printf("\n");
		int i;
		for(i=0;i<M;i++){
			Check(T,N);
		}
		DestroyTree(T);
		scanf("%d",&N);
	}
	return 0;	
}

