#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node {
    int coeff;
	int exp; /* 存储结点数据 */
    PtrToNode  Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode Poly; /* 单链表类型表示多项式 */

Poly Read(){
	int N, c, e;
    Poly p;
    int i = 0; //index
	p = (Poly) malloc (sizeof(struct Node));
	p -> Next = NULL;//initialize header
    scanf("%d",&N);//get the size
    Poly tmp = p;  // sentinel pointer
    for( i = 0; i < N; i++){
    	Poly q = (Poly) malloc ( sizeof ( struct Node ) );
    	scanf("%d",&c);
    	scanf("%d",&e);
    	q -> coeff = c;
    	q -> exp   = e;
    	q -> Next  = NULL;
    	tmp -> Next = q;
    	tmp = q;
	}
    return p;
}

void Print( Poly p){
	int flag = 0;
	Poly p1 = p -> Next;
	if (!p1) printf("0 0");
	while( p1 ){
		if (flag == 0){
			flag = 1;
			printf("%d %d",p1->coeff , p1->exp );
			p1 = p1 -> Next;
			continue;
			}
		printf(" %d %d",p1->coeff , p1->exp );
		p1 = p1 -> Next;
	}
	printf("\n");
}

Poly attach(int c, int e, Poly *pRear){
//Attach a new node to the rear of Poly. 
//Changing the value of pRear to the new rear
	Poly p = (Poly) malloc ( sizeof ( struct Node));
	p -> coeff = c;
    p -> exp   = e;
    p -> Next  = NULL;
    (*pRear) -> Next = p; //attach the new node
    (*pRear) = p; //update the pointer
}

Poly addPoly( Poly p1, Poly p2){
    Poly p = (Poly) malloc ( sizeof ( struct Node ) );
    p -> Next = NULL; //initialize the header
    Poly rear = p;//tmp save the header, tmp2 to add node to p
	int c,e;
    int sumCoeff = 0;
    p1 = p1 -> Next;
    p2 = p2 -> Next;
    while(p1 && p2 ){
        if(p1 -> exp > p2 -> exp ){
        	c = p1 -> coeff;
            e = p1 -> exp;
            attach(c,e,&rear);
            p1 = p1 -> Next;
            //printf("1\n");
        }
        else if(p1 -> exp < p2 -> exp){
            c = p2 -> coeff;
            e = p2 -> exp;
			attach(c,e,&rear);
			p2 = p2 -> Next;
            //printf("2\n");
        }
        else if(p1 -> exp == p2 -> exp ){
            sumCoeff = p1 -> coeff + p2 -> coeff;
            //printf("%d \n",sumCoeff);
            c = sumCoeff;
            e = p1 -> exp;
            if (sumCoeff!=0){//if the sum of coeff cancel we dont add term to the result
                attach(c,e,&rear);
			  //  printf("3a\n");
            }
            p1 = p1 -> Next;
            p2 = p2 -> Next;
            
        }
    }
    if (p1 == NULL && p2 == NULL) {
    	//printf("4\n");
        return p;
    }
    if (p1 == NULL ) {
    	//printf("5\n");
		while(p2){
			c = p2 -> coeff;
            e = p2 -> exp;
			attach(c,e,&rear);
			p2 = p2 -> Next;
		}
		return p;
    }
    if (p2 == NULL ) {
    	//printf("6\n");
        	while(p1){
			c = p1 -> coeff;
            e = p1 -> exp;
			attach(c,e,&rear);
			p1 = p1 -> Next;
		}
		return p;
        }
}
Poly multiplyPoly(Poly p1, Poly p2){
	Poly p = (Poly) malloc (sizeof (struct Node) );
	p -> Next = NULL;
	p1 = p1 ->Next;
	p2 = p2 ->Next;
	Poly q = p2;//save the header of p2;
	int c=0,e=0;
	if (!p1 || !p2) return p;//if one poly is zero, then return zero.
	while(p1 ){
		//printf("7\n");
		while(p2){
			//printf("8\n");
			c = p1 -> coeff * p2 -> coeff;
			e = p1 -> exp + p2 -> exp;
			Poly tmp = (Poly) malloc (sizeof (struct Node) );
			Poly tmp2 = tmp;
			attach(c,e,&tmp2);
			//printf("c=%d e=%d \n",c,e);
			//printf("print the tmp\n");
			//Print(tmp);
			p = addPoly(p,tmp); // here we do the addition
			free(tmp);
			free(tmp2);
			p2 = p2 -> Next;
		}	
		p1 = p1 -> Next;	
	    p2 = q;
	}
    return p; 
}

int main(){
	freopen("3.6.txt","r",stdin);
	Poly p1, p2, p3, p4;
	p1 = Read();
	p2 = Read();
	/*
	printf("print the p1\n");
	Print (p1);
	printf("print the p2\n");
	Print (p2);
	p3 = addPoly(p1, p2);*/

	p3 = addPoly(p1, p2);
	
	p4 = multiplyPoly(p1,p2);
	//printf("print the prod\n");
	Print (p4);
	//printf("print the sum\n");
	Print (p3);
		/*
	

	p3 = multiplyPoly(p1,p2);
	p1 = multiplyPoly(p1,p2);
	printf("print the prod\n");
	Print (p3);
	printf("print the p1\n");
	Print (p1);
	printf("print the p2\n");
	Print (p2);
    */
	return 0;
}


