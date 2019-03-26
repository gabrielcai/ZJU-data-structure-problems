//ϰ��3.5 ������ĵ�����m��Ԫ�� ��20 �֣�
//�����ʱ��Ϳռ��϶������ܸ�Ч���㷨���ڲ��ı������ǰ���£�����ʽ�洢�����Ա�ĵ�����m��>0����Ԫ�ء�

//two pointer, P2 is m step ahead of P1;
//if P2 = END then P1 is the last m-th element in the linked list. 
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* �洢������� */
    PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

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
