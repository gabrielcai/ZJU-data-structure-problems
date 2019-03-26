#include <stdio.h>
#include <stdlib.h>

#define MaxNodes 10
#define Null -1

typedef char ElementType;
typedef int Tree;

struct TreeNode{
	ElementType Element;
	Tree Lc;
	Tree Rc;
}T1[ MaxNodes ], T2[ MaxNodes ];

//Tree BuildTree( struct TreeNode  T[], FILE * myFile);
Tree BuildTree( struct TreeNode  T[]);
int Isomorphic(Tree R1, Tree R2);
void InOrderPrintTree(struct TreeNode T[], Tree R);



int main(){
	Tree R1, R2; //two roots;actually position of roots in the T1 T2 array;
//	FILE *myFile;
//    myFile = fopen("3.1.txt", "r");

//	R1 = BuildTree(T1, myFile);
//	R2 = BuildTree(T2, myFile);
//	InOrderPrintTree(T1,R1);printf("\n");
//	InOrderPrintTree(T2,R2);printf("\n");
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if ( Isomorphic( R1, R2)) printf("Yes\n");
	else printf("No\n");
	return 0;
}
//Tree BuildTree( struct TreeNode  T[], FILE * myFile){
Tree BuildTree( struct TreeNode  T[]){
	int N;
	int i;
	scanf("%d", &N);
	int isChild[N]; // flag that n-th node is child of some other nodes
	if(N){
		for ( i = 0; i < N; i++) isChild[i] = 0; 	
		for ( i = 0; i < N; i++){
			char l,r;
			scanf("\n%c %c %c", &T[i].Element, &l, &r);
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
			break;
		}
	}
	Root = i;
	return Root;
	}

void InOrderPrintTree(struct TreeNode T[], Tree R){
	if (Null != R) {
		InOrderPrintTree(T, T[R].Lc);
		printf("%c ", T[R].Element);
		InOrderPrintTree(T, T[R].Rc);
	}
}

int Isomorphic(Tree R1, Tree R2){
	if( R1 == Null && R2 == Null) 
		return 1;
	if( (R1 == Null && R2 != Null) || (R1 != Null && R2 == Null)) 
		return 0;
	if(T1[R1].Element == T2[R2].Element )
		return  Isomorphic(T1[R1].Lc, T2[R2].Lc) * Isomorphic(T1[R1].Rc, T2[R2].Rc) + 
		Isomorphic(T1[R1].Lc, T2[R2].Rc) * Isomorphic(T1[R1].Rc, T2[R2].Lc);
	else return 0;
}
