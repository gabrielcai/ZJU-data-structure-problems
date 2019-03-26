//04-树4 是否同一棵二叉搜索树 （25 分）
//给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。
//
//输入格式:
//输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。
//
//简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。
//
//输出格式:
//对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。
//
//输入样例:
//4 2
//3 1 4 2
//3 4 1 2
//3 2 4 1
//2 1
//2 1
//1 2
//0
//输出样例:
//Yes
//No
//No
//鸣谢青岛大学周强老师补充测试数据！
//
//作者: 陈越
//单位: 浙江大学
//时间限制: 400 ms
//内存限制: 64 MB


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

