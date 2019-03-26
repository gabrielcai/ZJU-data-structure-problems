#include <stdio.h>
#define  ET int

typedef struct PNode * PtrToPNode;
struct PNode{
	ET Exp,Coeff;
	PtrToPNode Next;
};
typedef PtrToPNode Poly;

Poly Attach(Poly Rear,int E, int C){
//Attach (Exp,Coeff) to  Rear,
//return new Rear
	Poly tmp    = (Poly) malloc(sizeof(struct PNode));
	tmp->Exp   = E;
	tmp->Coeff = C;
	tmp->Next  = NULL;
	Rear->Next  = tmp;
	return tmp;
}
Poly Read(int N){
	Poly Header  = NULL;//empty header;
	Poly Rear 	 = Header;
	int i,Exp,Coeff;
	for(i=0;i<N;i++){
		scanf("%d %d",&Exp,&Coeff);
		Rear = Attach(Rear,Exp, Coeff);
	}
	Header = Header->Next;//remove the empty header;
	return Header; 
}

void Print(Poly P){
	int flag = 0;
	while(P->Next){
		if(!flag) printf("%dx^%d",P->Coeff,P->Exp);
		else printf("+%dx^%d",P->Coeff,P->Exp);
		P = P->Next;
	}
	printf("\n");
}


int main(){
	int N;
	freopen("3.6.txt","r",stdin);
	scanf("%d",&N);
	Poly P = Read(N);	
	Print(P);
	
}


