//04-树6 Complete Binary Search Tree （30 分）
//A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//Both the left and right subtrees must also be binary search trees.
//A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.
//
//Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.
//
//Input Specification:
//Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.
//
//Output Specification:
//For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
//
//Sample Input:
//10
//1 2 3 4 5 6 7 8 9 0
//Sample Output:
//6 3 8 1 5 7 9 0 2 4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxSize 1000
typedef int ET;
typedef struct TNode *Position;
typedef Position BinTree;

struct TNode{
	ET Data;
	BinTree Left;
	BinTree Right;
};


BinTree Insert( BinTree BST, ET X ){
	if(! BST) {
		BST = (BinTree) malloc (sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else{
		if(X >= BST->Data) BST->Right = Insert( BST->Right, X );
		else BST->Left = Insert( BST->Left, X );
	}
	return BST;
}

void LevelOrder(BinTree BST){
	if(BST){
		BinTree Queue[MaxSize], tmp;
		int Rear=0,Front=0;
		Queue[Rear++] = BST;
		int flag = 1;
		while(Front != Rear){
			tmp = Queue[Front++];
			if(flag) {
				printf("%d",tmp->Data)	;
				flag = 0;
			}
			else printf(" %d",tmp->Data)	;
			if(tmp->Left) Queue[Rear++] = tmp->Left;
			if(tmp->Right) Queue[Rear++] = tmp->Right;
		}
	}	
}


void quicksort(int A[], int lo, int hi) { 
	int i, j, pivot, temp;   
	if(lo == hi) return;  
	i=lo;  j=hi;  pivot= A[(lo+hi)/2];   /* Split the array into two parts */  
	do {    
		while (A[i] < pivot) i++;    
		while (A[j] > pivot) j--;    
		if (i<=j) {      
			temp= A[i];      
			A[i]= A[j];      
			A[j]=temp;      
			i++;      
			j--;    
		}  
	} while (i<=j);   
	if (lo < j) quicksort(A, lo, j); 
	if (i < hi) quicksort(A, i, hi);
}
int min(int a,int b){
	return a>b?b:a;
}
int findNl( int lo , int hi){//find the number of nodes in left subtree
	int Nl;//number of nodes in left subtree
    int H;
    int N = hi - lo + 1 ;
    if(N == 1) 
		return 0;
    else{
		H = ceil(log(N+1)/log(2));//height of tree;
		int X = min(N- pow(2,H-1)+1,pow(2,H-2));//number of nodes in the lowers layers of left subtree 
		Nl = pow(2,H-2)-1 + X;
		return Nl;
	}
    
}
BinTree BuildTree(int A[],int lo, int hi){
	//printf("%d %d\n",lo,hi);
	if (lo>hi) return NULL;
	BinTree T = NULL;//只有设为NULL才能插入。不然无地址
	int RootId = lo + findNl(lo,hi);
	//printf("%d\n",RootId);
    T = Insert(T, A[RootId]);
    T->Left  = BuildTree(A, lo,RootId-1);
    T->Right = BuildTree(A, RootId+1,hi);
	return T;
	}



int main(){
	freopen("4.6.txt", "r",stdin);
	int N;
	scanf("%d\n",&N);
	int i, A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	quicksort(A,0,N-1);
	for(i=0;i<N;i++){
	//	printf("%d",A[i]);
	}
	BinTree T = BuildTree(A,0,N-1);
	LevelOrder(T);
}
