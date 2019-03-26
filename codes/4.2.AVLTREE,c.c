//练习4.2 平衡二叉树的根 （25 分）
//将给定的一系列数字插入初始为空的AVL树，请你输出最后生成的AVL树的根结点的值。
#include <stdio.h>
#include <stdlib.h>
typedef int ET;
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode{
	ET Data;
	BinTree Left;
	BinTree Right;
	int Height;
};

int GetHeight(Position BST){
	if(!BST) return -1;//Null tree height 为 -1 
	else return BST->Height;
}

int GetBFactor(Position BST){//get balanced factor,  
	return 	GetHeight(BST->Left)-GetHeight(BST->Right);
}
int Max(int a, int b){
	return a>=b?a:b;
}

void UpdateHeight(Position P){
	P->Height = Max(GetHeight(P->Left),GetHeight(P->Right)) + 1;
}

Position LeftRotation(Position P){
	Position tmp = P->Right;
	P->Right = tmp->Left;
	tmp->Left = P;
	UpdateHeight(P);
	UpdateHeight(tmp);
	return tmp;
}

Position RightRotation(Position P){
	Position tmp = P->Left;
	P->Left = tmp->Right;
	tmp->Right = P;
	UpdateHeight(P);
	UpdateHeight(tmp);
	return tmp;
}

BinTree Insert( BinTree BST, ET X ){
	if(! BST) {
		BST = (BinTree) malloc (sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
		BST->Height = 0;
	} 
	else 
	if(X < BST->Data) {
		BST->Left = Insert( BST->Left, X );
		UpdateHeight(BST);
		if(GetBFactor(BST)==2){
			if(X < BST->Left->Data)//LL
				BST = RightRotation(BST);
			else{//LR
				BST->Left = LeftRotation(BST->Left);
				BST 	  = RightRotation(BST);
			}
		}
	}
	else
	if(X > BST->Data){
		BST->Right = Insert( BST->Right, X );	
		UpdateHeight(BST);
		if(GetBFactor(BST)==-2){
				if(X > BST->Right->Data)//RR
					BST = LeftRotation(BST);
				else{//RL
					BST->Right = RightRotation(BST->Right);
					BST 	   = LeftRotation(BST);
				}		
		} 
	}
	//UpdateHeight(BST);
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

int main(){
	//freopen("4.2.txt","r",stdin);
	int N;//number of nodes
	scanf("%d",&N);
    BinTree T = BuildTree(N);
	printf("%d",T->Data);
	
	return 0; 
}
