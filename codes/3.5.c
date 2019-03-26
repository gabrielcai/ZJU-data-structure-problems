//习题3.5 求链表的倒数第m个元素 （20 分）
//请设计时间和空间上都尽可能高效的算法，在不改变链表的前提下，求链式存储的线性表的倒数第m（>0）个元素。

//two pointer, P2 is m step ahead of P1;
//if P2 = END then P1 is the last m-th element in the linked list. 
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

ElementType Find( List L, int m ){
	if(m<1 || !L) return ERROR;
	PtrToNode P1 = L, P2 = L;
	int i;
	for(i=0;i<m;i++){
		if(P2->Next) P2=P2->Next;
		else return ERROR;
	}
	
	while(P2){
		P1 = P1->Next;
		P2 = P2->Next;
	}
	return P1->Data;
} 
