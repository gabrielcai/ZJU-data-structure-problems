//04-Ê÷5 Root of AVL Tree £¨25 ·Ö£©
//An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
//
// 
// 
//
//Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
//Input Specification:
//Each input file contains one test case. For each case, the first line contains a positive integer N (¡Ü20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
//
//Output Specification:
//For each test case, print the root of the resulting AVL tree in one line.
//
//Sample Input 1:
//5
//88 70 61 96 120
//Sample Output 1:
//70
//Sample Input 2:
//7
//88 70 61 96 120 90 65
//Sample Output 2:
//88
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
	if(!BST) return -1;
	else return BST->Height;
}

int GetBFactor(Position BST){
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
	UpdateHeight(tmp);
	UpdateHeight(P);
	return tmp;
}

Position RightRotation(Position P){
	Position tmp = P->Left;
	P->Left = tmp ->Right;
	tmp->Right = P;
	UpdateHeight(tmp);
	UpdateHeight(P);
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
		if(GetBFactor(BST)==-2){
				if(X > BST->Right->Data)//RR
					BST = LeftRotation(BST);
				else{//RL
					BST->Right = RightRotation(BST->Right);
					BST 	   = LeftRotation(BST);
				}		
		} 
	}
	UpdateHeight(BST);
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
	BinTree T ;
	freopen("4.5.txt", "r",stdin);
	int N;
	scanf("%d\n",&N);
	T = BuildTree(N);
	printf("%d",T->Data);
	return 0;	
}
